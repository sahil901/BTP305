/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: October/19th/2020
Date Due: October/25th/2020
Prof Name: Cornel Barna
Class Section: NBB
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// File Headers 
#include <iostream>
#include <algorithm> // find 
#include <iomanip>
#include "Book.h"
using namespace std;

// sdds namespace 
namespace sdds
{
	// default constructor 
		// setting everything to empty state
	Book::Book()
	{
		book_author = "";
		book_title = "";
		book_country = "";
		book_description = "";
		book_year = 0;
		book_price = 0.0;
	}

	// return title of book (query)
	const std::string& Book::title() const
	{
		return this->book_title;
	}

	// return country of where book was published (query)
	const std::string& Book::country() const
	{
		return this->book_country;
	}

	// return which year book was published (query)
	const size_t& Book::year() const
	{
		return this->book_year;
	}

	// return price by reference  
	double& Book::price()
	{
		return this->book_price;
	}

	// trim function
		// learning and using trim function 
	std::string Book::trim(std::string s)
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
	Book::Book(const std::string& strBook)
	{
		// temporary variable to be able to remove spaces 
		std::string t_remove = strBook; 

		// author 
			// trim the spaces from the front and back and find comma 
		book_author = trim(t_remove.substr(0, t_remove.find(","))); 

			// search for the first comma and erase it and the space after  
		t_remove.erase(0, t_remove.find_first_of(",") + 1);
		
		// title 
			// trim the spaces from the front and back and find comma 
		book_title = trim(t_remove.substr(0, t_remove.find(",")));

			// search for the first comma and erase it and the space after 
		t_remove.erase(0, t_remove.find_first_of(",") + 1);

		// country 
			// trim the spaces from the front and back and find comma 
		book_country = trim(t_remove.substr(0, t_remove.find(",")));

			// search for the first comma and erase it and the space after 
		t_remove.erase(0, t_remove.find_first_of(",") + 1);

		// price 
			// trim the spaces from the front and back and find comma 
		book_price = stod(trim(t_remove.substr(0, t_remove.find(","))));

			// search for the first comma and erase it and the space after 
		t_remove.erase(0, t_remove.find_first_of(",") + 1);

		// year 
			// trim the spaces from the front and back and find comma 
		book_year = stoi(trim(t_remove.substr(0, t_remove.find(","))));

			// search for the first comma and erase it and the space after 
		t_remove.erase(0, t_remove.find_first_of(",") + 1);
			
		// description 
			// trim necessary spaces 
		book_description = trim(t_remove);
	}

	// friend insertion operator 
		// output in specified format 
	std::ostream& operator<<(std::ostream& os, const Book& s)
	{
		os << setw(20) << s.book_author << " | " << setw(22) << s.book_title << " | " << setw(5) << s.book_country << " | " << setw(4) << s.book_year << " | " << setw(6) << fixed << setprecision(2) << s.book_price << " | " << s.book_description << endl;
		return os;
	}
}