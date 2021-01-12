/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: October/15th/2020
Date Due: October/18th/2020
Prof Name: Cornel Barna
Class Section: NBB
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// File Headers 
#ifndef _SDDS_RESTAURANT_H
#define _SDDS_RESTAURANT_H
#include "Reservation.h"

// sdds namespace 
namespace sdds
{
	// restaurant class
	class Restaurant
	{		
		// dynamically allocated array  
		Reservation* res_array;  

		// reservations made 
		size_t res_num; 

		// public 
	public:

		// constructor which keeps copies 
		Restaurant(Reservation* reservations[], size_t cnt);

		// return number of reservations made 
		size_t size() const;

		// all special member functions that are needed: 

		// constructor 
		Restaurant(); 

		// destructor 
		~Restaurant(); 

		// copy constructor 
		Restaurant(Restaurant& s); 

		// copy assignment operator 
		Restaurant& operator=(const Restaurant& s); 

		// move constructor 
		Restaurant(Restaurant&& s); 

		// move assignment operator 
		Restaurant& operator=(Restaurant&& s); 

		// friend insertion helper 
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant);
	};
}
#endif