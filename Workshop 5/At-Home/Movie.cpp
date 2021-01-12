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
#include "Movie.h"
#include "Book.h"

// sdds namespace 
namespace sdds
{
	// constructor
		// setting everything to empty state
	Movie::Movie()
	{
		m_title = "";
		m_description = "";
		m_release = 0;
	}

	// return title of movie (query)
	const std::string& Movie::title() const
	{
		return m_title;
	}

	// trim function
	// learning and using trim function 
	std::string Movie::trim(std::string s)
	{
		// where theres a space at the front remove it 
		while (s.front() == ' ')
		{
			s = s.substr(1, s.length() - 1);
		}

		// while theres space at the back remove it 
		while (s.back() == ' ')
		{
			s = s.substr(0, s.length() - 1);
		}
		return s;
	}

	// constructor that receives a reference to an unmodifiable string 
	Movie::Movie(const std::string& strMovie)
	{
		// temporary variable to be able to remove spaces 
		std::string t_remove = strMovie;

		// title 
			// trim the spaces from the front and back and find comma 
		m_title = trim(t_remove.substr(0, t_remove.find(",")));

		// search for the first comma and erase it and the space after  
		t_remove.erase(0, t_remove.find_first_of(",") + 1);

		// year 
			// trim the spaces from the front and back and find comma 
		m_release = stoi(trim(t_remove.substr(0, t_remove.find(","))));

		// search for the first comma and erase it and the space after 
		t_remove.erase(0, t_remove.find_first_of(",") + 1);

		// description 
			// trim necessary spaces 
		m_description = trim(t_remove);
	}

	// friend insertion operator
		// output in specified format 
	std::ostream& operator<<(std::ostream& os, const Movie& movie)
	{
		os << std::setw(40) << movie.m_title << " | " << std::setw(4) << movie.m_release << " | " << movie.m_description << std::endl;
		return os;
	}
}