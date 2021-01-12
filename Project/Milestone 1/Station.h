/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date Started: November/1st/2020
Date of completion: November/10th/2020
Date Due: November/14th/2020
Prof Name: Cornel Barna
Class Section: NBB
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// File Headers 
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <iomanip>
#include <string>

// Station class
class Station
{
	// name of item handled 
	std::string name_item;
	
	// description of station 
	std::string desc; 

	// next serial number to be assigned 
	int n_serialNum; 

	// current items left in stock
	int current_stock; 

	// max characters required (static)
	static size_t m_widthField; 

	// used to generate ID's 
	static int id_generator; 

	// id 
	unsigned int s_id;

	// public 
  public: 
	  
	  // constructor 
	  Station();

	  // custom constructor 
	  Station(const std::string& station);

	  // return name of current station
	  const std::string& getItemName() const;

	  // return next serial number to be used 
	  unsigned int getNextSerialNumber();

	  // return remaining quantity of current station
	  unsigned int getQuantity() const; 

	  // update quantity by subtracting one 
	  void updateQuantity(); 

	  // display info in specified format 
	  void display(std::ostream& os, bool full) const; 
};

#endif // !ITEM_H