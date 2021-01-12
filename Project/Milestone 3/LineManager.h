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
#ifndef _LINE_MANAGER_H
#define _LINE_MANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"
#include "Utilities.h"
#include "Workstation.h"

// linemanager class
class LineManager
{
	// container containing refs and other specifed  
	std::vector<Workstation*> AssemblyLine; 

	// queue of customer orders to be filled
	std::deque<CustomerOrder> ToBeFilled; 

	// queue of completeted customer orders 
	std::deque<CustomerOrder> Completed; 

	// # of customerorder objs the assembly line started w/ 
	unsigned int m_cntCustomerOrder; 

	// public 
public: 

	// custom constructor 
	LineManager(const std::string& line, std::vector<Workstation*>& work, std::vector<CustomerOrder>& order); 

	// perform one cycle of operations on assemly line 
	bool run(std::ostream& os); 
	
	// displays all the orders that were completed
	void displayCompletedOrders(std::ostream& os) const; 

	// display all stations on the assembly line in the order they were received from the client
	void displayStations() const; 

	// display all stations on the assembly line in the order they are linked 
	void displayStationsSorted() const; 

	// created my own function to reduce repeating code
    size_t statrep() const;
};
#endif // !_LINE_MANAGER_H