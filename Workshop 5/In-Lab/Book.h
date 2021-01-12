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
#ifndef _SDDS_BOOK_H
#define _SDDS_BOOK_H
#include <string> 

// sdds namespace
namespace sdds
{
	// book class 
	class Book
	{
		// author of book  
		std::string book_author;

		// title of book
		std::string book_title;

		// country of where book was published 
		std::string book_country;

		// short description highlighting book
		std::string book_description;

		// year book was published 
		size_t book_year;
		
		// price being charged for book
		double book_price;

		// public 
	public:

		// default constructor 
		Book();

		// return title of book (query)
		const std::string& title() const; 

		// return country of where book was published (query)
		const std::string& country() const; 

		// return which year book was published (query)
		const size_t& year() const;

		// return price by reference  
		double& price(); 

		// trim function
		std::string trim(std::string s);

		// constructor that receives a reference to an unmodifiable string 
		Book(const std::string& strBook); 

		// friend insertion operator 
		friend std::ostream& operator<<(std::ostream& os, const Book& s);
	};
}
#endif // !_SDDS_BOOK_H