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
#ifndef _SDDS_MOVIE_H
#define _SDDS_MOVIE_H
#include <iostream>
#include <iomanip>

// sdds namespace 
namespace sdds
{
	// movie class 
	class Movie
	{
		// movie title 
		std::string m_title;

		// year which movie was released 
		int m_release; 

		// description of movie 
		std::string m_description; 

		// public 
	public: 
		
		// default constructor 
		Movie(); 

		// return title of movie (query)
		const std::string& title() const; 

		// trim function
		std::string trim(std::string s);

		// recieves movie through reference string 
		Movie(const std::string& strMovie); 

		// friend insertion operator 
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie); 

		// Type T template 
		template<typename T>

		// function calls the overloaded operator()
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_title); 
			spellChecker(m_description);  
		}
	};
}
#endif // !_SDDS_MOVIE_H