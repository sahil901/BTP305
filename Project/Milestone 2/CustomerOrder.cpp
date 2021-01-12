/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date Started: November/9th/2020
Date of completion: November/13th/2020
Date Due: November/21th/2020
Prof Name: Cornel Barna
Class Section: NBB
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// File Headers
#include "CustomerOrder.h"

// setting the default value for widthField
size_t CustomerOrder::m_widthField = 0;

// constructor 
	// setting everything to safe empty state 
CustomerOrder::CustomerOrder()
{
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr; 
}

// destructor
	// deallocating memory for pointer 
CustomerOrder::~CustomerOrder()
{
	// iterate through orders 
	for (size_t i = 0; i < m_cntItem; i++)
	{
		delete m_lstItem[i];
		m_lstItem[i] = nullptr; 
	}
	delete[] m_lstItem; 
}

// custom constructor 
CustomerOrder::CustomerOrder(const std::string& order)
{
	// for extracting 
	Utilities ext_temp; 

	// booelan
	bool local = true; 

	// starting position 
	size_t start = 0; 

	// extracting 
		// name 
	m_name = ext_temp.extractToken(order, start, local);

		// product 
	m_product = ext_temp.extractToken(order, start, local);
		
	// count from start to end for items in the customer's order
	m_cntItem = std::count(order.begin(), order.end(), ext_temp.getDelimiter()) - 1;

	// allocating mem
	m_lstItem = new Item * [m_cntItem];

	// iterate through orders 
		// extract items in list 
	for (size_t i = 0; i < m_cntItem; i++)
		m_lstItem[i] = new Item(ext_temp.extractToken(order, start, local));

	// if widthField is less than the temporary widthField then make them =
	if (m_widthField < ext_temp.getFieldWidth())
		m_widthField = ext_temp.getFieldWidth(); 
}

// copy constructor 
	// throws error message, copy operations not allowed 
CustomerOrder::CustomerOrder(const CustomerOrder& order)
{
	throw "Copy Operations are not allowed!";
}

// move constructor 
	// use no except (specified to do so)
CustomerOrder::CustomerOrder(CustomerOrder&& order) noexcept
{
	// set pointer to null 
	m_lstItem = nullptr; 

	*this = std::move(order);
}

// move assignment operator
	// use no except (specified to do so)
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept
{
	// if not same then do following 
	if (this != &order)
	{
		// list item
			// deallocaing memory, making copy, and seeting to nullptr
		if (m_lstItem != nullptr)
		{
			for (size_t i = 0; i < m_cntItem; i++)
			{
				delete m_lstItem[i];
				m_lstItem[i] = nullptr;
			}
			delete[] m_lstItem;
		}

		// making copies of varaibles 
			// name 
		m_name = order.m_name;
		order.m_name = "";

			// prodcut 
		m_product = order.m_product;
		order.m_product = "";

			// customer order items 
		m_cntItem = order.m_cntItem;
		order.m_cntItem = 0;

			// list 
		m_lstItem = order.m_lstItem;
		order.m_lstItem = nullptr; 
	}
	return *this; 
}

// return true or false based on param
bool CustomerOrder::isOrderFilled() const
{
	// creating local boolean to check and return 
	bool local = false; 

	// iterate through orders 
	for (size_t i = 0; i < m_cntItem; i++)
	{
		// if not filled than return false 
		if (!m_lstItem[i]->m_isFilled)
		{
			return local; 
		}
	}

	// otherwise return true 
	return local = true;
}

// returns info of item in param
bool CustomerOrder::isItemFilled(const std::string& itemName) const
{
	// creating local boolean to check and return 
	bool local = true; 

	// iterate through orders 
	for (size_t i = 0; i < m_cntItem; i++)
		// if paramater and list item the same then set it equal to the boolean 
		if (m_lstItem[i]->m_itemName == itemName)
		{
			local = m_lstItem[i]->m_isFilled;
		}
	return local; 
}

// fills item in current order 
void CustomerOrder::fillItem(Station& station, std::ostream& os)
{
	// iterate through orders 
	for (size_t i = 0; i < m_cntItem; i++)
	{
		// if order has item then do following 
		if (m_lstItem[i]->m_itemName == station.getItemName())
		{
			// if not = 0 then... 
			if (station.getQuantity() != 0)
			{
				station.updateQuantity();

				// updating fillstate
				m_lstItem[i]->m_isFilled = true; 

				// updating serial num
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();

				// output in specified format 
				os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
			}
			
			// else output in the specified format 
			else
			{
				os << "Unable to fill " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
			}
		}
	}
}

// displays info in specified format 
void CustomerOrder::display(std::ostream& os) const
{
	os << m_name << " - " << m_product << std::endl;

	// iterate through orders 
		// output information in specified format 
	for (size_t i = 0; i < m_cntItem; i++)
	{
		// default format 
		os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] " << std::setfill(' ') << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";

		// if fillState equals to true then set string to FILLED if not then set string to MISSING
		m_lstItem[i]->m_isFilled == true ? os << "FILLED" : os << "MISSING";

		// ouput endl; 
		os << std::endl;
	}
}