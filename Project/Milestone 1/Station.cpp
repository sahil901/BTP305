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
#include "Station.h"
#include "Utilities.h"

size_t Station::m_widthField = 0; 
int Station::id_generator = 0;

// constructor 
	// setting everything to safe empty state 
Station::Station()
{
	name_item = "\0"; 
	desc = "\0";
	n_serialNum = 0;
	current_stock = 0;
}

// custom constructor 
Station::Station(const std::string& station)
{
	// Utilities obj (extract each token)
	Utilities s; 

	// starting position at index 0 
	size_t start_position = 0; 

	// boolean set to true 
	bool s_boolean = true;

	// name of item
	name_item = s.extractToken(station, start_position, s_boolean); 

	// for id 
	s_id = ++id_generator; 

	// starting serial number
	n_serialNum = std::stoi(s.extractToken(station, start_position, s_boolean)); 

	// quantity in stock
	current_stock = std::stoi(s.extractToken(station, start_position, s_boolean));

	// description 
	desc = s.extractToken(station, start_position, s_boolean);

	// if the max characters displayed is less than field width of current s then set them equal to eachother 
	if (m_widthField < s.getFieldWidth())
	{
		m_widthField = s.getFieldWidth();
	}
}

// return name of current station
const std::string& Station::getItemName() const
{
	return name_item;
}

// return next serial number to be used 
unsigned int Station::getNextSerialNumber()
{
	return n_serialNum++;
}

// return remaining quantity of current station
unsigned int Station::getQuantity() const
{
	return current_stock;
}

// update quantity by subtracting one 
void Station::updateQuantity()
{
	if (current_stock > 0)
	{
		current_stock--;
	}
}

// display info in specified format 
void Station::display(std::ostream& os, bool full) const
{	
	// too avoid code duplication 
	os << "[" << std::setw(3) << std::setfill('0') << std::right << s_id << "]" << " Item: " << std::left << std::setw(m_widthField/2) << std::setfill(' ') << getItemName() << "[";

	// if the bool is false do the following 
	if (!full)
	{
		os << std::right << std::setw(6) << std::setfill('0') << n_serialNum << "]" << std::endl;
	}

	// else do the following 
	else
	{
		os << std::setw(6) << std::setfill('0') << std::right << n_serialNum << "]" << std::setfill(' ') << " Quantity: " << std::setw(m_widthField/2) << std::left << current_stock << "Description: " << desc << std::endl;
	}
}