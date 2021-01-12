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
#include "Utilities.h"

// defining the delimiter than all utilities object will share 
char Utilities::m_delimiter = '\0';

// constructor 
	// setting everything to safe empty state 
Utilities::Utilities()
{
	m_widthField = 1;
}

// setting field width 
void Utilities::setFieldWidth(size_t newWidth)
{
	m_widthField = newWidth;
}

// return field width 
size_t Utilities::getFieldWidth() const
{
	return m_widthField;
}

// set delimiter 
void Utilities::setDelimiter(char newDelimiter)
{
	m_delimiter = newDelimiter;
}

// return delimiter 
char Utilities::getDelimiter()
{
	return m_delimiter; 
}

// extract tokens and do other specified tasks 
std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	// starting at index 0
	size_t position = 0;
	
	// string that'll save extracted word 
	std::string save; 

	// boolean to set to T or F 
	more = false; 

	// if length larger then position then do following 
	if (next_pos < str.length())
	{
		// extract the next token 
		position = str.find(m_delimiter, next_pos);

		// if not highest value then do following 
		if (position != std::string::npos)
		{
			// save the word that was found 
			save = str.substr(next_pos, position - next_pos);
		}

		// else do the following 
		else
		{
			save = str.substr(next_pos); 
		}

		// if string empty then throw following exception
		if (save.empty())
		{
			throw "Nothing Found";
		}

		// else do following 
			// set bool to true
		else
		{
			more = true;
		}

		// if length is more then the widthField then do the following
			// set widthField and length to eachother 
		if (m_widthField < save.length())
		{
			m_widthField = save.length();
		}
	}
	next_pos = position + 1;
	return save; 
}