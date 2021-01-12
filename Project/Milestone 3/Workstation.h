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
#ifndef _WORKSTATION_H
#define _WORKSTATION_H
#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

// WorkStation class inherting from public members in Station 
class Workstation : public Station
{
	// deque 
	std::deque<CustomerOrder> m_orders; 

	// pointer 
	Workstation* m_pNextStation;

	// public 
public: 

	// custom constructor 
	Workstation(const std::string& work);

	// copy and move operations set to delete 
		// copy operations 
	// copy consturctor 
	Workstation(const Workstation&) = delete;
	
	// copy assignment operator
	Workstation& operator = (const Workstation&) = delete;

		// move operations 
	// move constructor 
	Workstation(Workstation&&) = delete;

	// move assignment operator
	Workstation& operator=(Workstation&&) = delete;

	// run cycle of assembly line
	void runProcess(std::ostream&); 

	// if order at front then do specified 
	bool moveOrder(); 

	// stores provided station obj 
	void setNextStation(Station& station);

	// (query) return next station on assembly line 
	const Workstation* getNextStation() const;

	// if queue completed then do specified
	bool getIfCompleted(CustomerOrder& order); 

	// displays info in specified format 
	void display(std::ostream&) const; 

	// moves param onto back of queue  
	Workstation& operator+=(CustomerOrder&& work); 
};
#endif // !_WORKSTATION_H