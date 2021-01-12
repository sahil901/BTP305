/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: October/14th/2020
Date Due: October/18th/2020
Prof Name: Cornel Barna
Class Section: NBB
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// File Headers 
#ifndef _SDDS_CONFIRMATIONSENDER_H
#define _SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"

// sdds namespace
namespace sdds
{
	// confirmationSender class
	class ConfirmationSender
	{
		// dynamically allocated array of pointers 
		const Reservation** t_res;

		// how many people reserved 
		size_t num_res = 0;  

		// public 
	public:

		// add address of reservation res to array
		ConfirmationSender& operator+=(const Reservation& res); 

		// remove address of reservation res from array 
		ConfirmationSender& operator-=(const Reservation& res);

		// all special member functions that are needed: 

		// constructor 
		ConfirmationSender(); 

		// destructor 
		~ConfirmationSender(); 

		// copy constructor 
		ConfirmationSender(const ConfirmationSender& s); 
		
		// copy assignment operator 
		ConfirmationSender& operator=(const ConfirmationSender& s); 
		
		// move constructor 
		ConfirmationSender(ConfirmationSender&& s); 
		
		// move assignment operator 
		ConfirmationSender& operator=(ConfirmationSender&& s);

		// friend inseration operator 
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& s); 
	};
}
#endif // !_SDDS_CONFIRMATIONSENDER_H