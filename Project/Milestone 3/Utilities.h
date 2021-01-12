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
#ifndef UTILITIES_H
#define UTILITIES_H
#include <iostream>

// Utilities class
class Utilities
{
	// length of extracted token
	size_t m_widthField;

	// token seperator 
	static char m_delimiter;

	// public
public:

	// constructor 
	Utilities();

	// set field width of current obj 
	void setFieldWidth(size_t newWidth);

	// return field width of current obj 
	size_t getFieldWidth() const;

	// extract tokens and do other specified tasks 
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

	// set delimiter for class 
	static void setDelimiter(char newDelimiter);

	// return delimiter character 
	static char getDelimiter();
};
#endif // !UTILITIES_H