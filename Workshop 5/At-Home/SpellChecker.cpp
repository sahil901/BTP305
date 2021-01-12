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
#include "SpellChecker.h"

// sdds namespace 
namespace sdds
{
	// constructor which recieves string 
	SpellChecker::SpellChecker(const char* filename)
	{
		// loading the file 
		std::ifstream file(filename); 

		// local string variable 
		std::string local; 

		// if the file is not correct throw the following error message 
		if (!file)
		{
			throw "Bad file name!"; 
		}

		// else do following 
		else
		{
			// iterate through 
			for (size_t i = 0; i < s_size; i++)
			{
				// grab the lines from the file 
				std::getline(file, local); 

				// store bad words 
				m_badWords[i] = local.substr(0, local.find(" ")); 
				
				// store good words 
				m_goodWords[i] = local.substr(local.find_last_of(" ") + 1, local.length()); 
			}

			// close the file, all work is done 
			file.close(); 
		}
	}

	// operator searches for badwords and replaces them
	void SpellChecker::operator()(std::string& text) const
	{
		// iterating through
		for (size_t i = 0; i < s_size; i++)
		{
			while (text.find(m_badWords[i]) != std::string::npos)
			{
				// replace the bad words with the good words 
				text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
			}
		}
	}
}