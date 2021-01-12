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
#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H
#include<iostream>
#include<iomanip>
#include<vector>
#include <algorithm>
#include <ostream>
#include<string>
#include "Station.h"
#include "Utilities.h"

// prof's provided code 
struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};

// customerorder class
class CustomerOrder
{
	// name 
	std::string m_name; 

	// name of product 
	std::string m_product;

	// number of items in customer order 
	unsigned int m_cntItem; 

	// dynamic array
	Item** m_lstItem;

	// max width of field (display related)
	static size_t m_widthField; 

	// public 
public:

	// default constructor 
	CustomerOrder(); 

	// destructor 
	~CustomerOrder();

	// custom constructor 
	CustomerOrder(const std::string& order);

	// copy constructor 
	CustomerOrder(const CustomerOrder& order);

	// copy operator (not supposed to implement in cpp)
	CustomerOrder& operator=(const CustomerOrder&) = delete;

	// move constructor 
		// no except specified by prof
	CustomerOrder(CustomerOrder&&) noexcept;

	// move assignment operator
		// no except specified by prof
	CustomerOrder& operator=(CustomerOrder&& order) noexcept;

	// return true or false based on param
	bool isOrderFilled() const;

	// returns info of item in param
	bool isItemFilled(const std::string& itemName) const; 

	// fills item in current order 
	void fillItem(Station& station, std::ostream& os); 

	// displays info in specified format 
	void display(std::ostream& os) const; 
};
#endif // !CUSTOMERORDER_H