/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date Started: November/15th/2020
Date of completion: November/24th/2020
Date Due: November/28th/2020
Prof Name: Cornel Barna
Class Section: NBB
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// File Headers
#include "Workstation.h"

// custom constructor
	// set to nullptr 
Workstation::Workstation(const std::string& work) : Station(work)
{
	m_pNextStation = nullptr; 
}

// run cycle of assembly line
void Workstation::runProcess(std::ostream& work)
{
	// if customerorders in queue then fill in the front
	if (!m_orders.empty())
	{
		m_orders.front().fillItem(*this, work); 
	}
}

// if order at front then do specified 
bool Workstation::moveOrder()
{
	// create bool and set to false 
	bool check = false;

	// if queue is empty then return false 
	if (m_orders.empty())
	{
		return check;
	}

	// if order at the front of the queue is filled then remove the queue and do the following 
	if (m_orders.front().isItemFilled(getItemName()))
	{
	   *m_pNextStation += std::move(m_orders.front());
		m_orders.pop_front();
		return true;
	}

	// otherwise return the false bool 
	else
	{
		return check;
	}
}

// stores provided station obj 
void Workstation::setNextStation(Station& station)
{
	// if this isn't the station then do the following*
	if (this != &station)
	{
		m_pNextStation = static_cast <Workstation*>(&station);
	}
}

// (query) return next station on assembly line 
const Workstation* Workstation::getNextStation() const
{
	return m_pNextStation; 
}

// if queue completed then do specified
bool Workstation::getIfCompleted(CustomerOrder& order)
{
	// create bool and set to false 
	bool check = false; 

	// if order empty then return false
	if (m_orders.empty())
	{
		return check;
	}
	
	// if order at front is compelte then remove it from queue and return true
	if (m_orders.front().isOrderFilled())
	{
		order = std::move(m_orders.front());
		m_orders.pop_front();
		return true;
	}

	// otherwise return false bool 
	else
	{
		return check;
	}
}

// displays info in specified format 
void Workstation::display(std::ostream& stat) const
{
	// the first half of the output should be like this ITEM_NAME -->
	stat << getItemName() << " --> ";

	// if not null then output in the following format 
	if (m_pNextStation != nullptr)
	{
		stat << getNextStation()->getItemName() << std::endl;
	}

	// else ouput this 
	else
	{
		stat << "END OF LINE" << std::endl; 
	}
}

// moves param onto back of queue  
Workstation& Workstation::operator+=(CustomerOrder&& work)
{
	m_orders.push_back(std::move(work));
	return *this;
}