/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: October/24th/2020
Date Due: October/25th/2020
Prof Name: Cornel Barna
Class Section: NBB
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// File Headers 
#ifndef _SDDS_SPELLCHECKER_H
#define _SDDS_SPELLCHECKER_H
#include <iostream>
#include <string>
#include <fstream>

// staticlly allocated array of size 5
const size_t s_size = 5; 

// sdds namespace 
namespace sdds
{
	// spellchecker class 
	class SpellChecker
	{
		// mispelled words
		std::string m_badWords[s_size];

		// correct words 
		std::string m_goodWords[s_size];

		// public 
	public:

		// constructor which recieves string 
		SpellChecker(const char* filename);

		// operator searches for badwords and replaces them
		void operator()(std::string& text) const;
	};
}
#endif