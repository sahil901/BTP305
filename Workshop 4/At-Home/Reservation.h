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
#ifndef _SDDS_RESERVATION_H
#define _SDDS_RESERVATION_H
#include <string> // allows substr, find, erase, and stoi 

// sdds namespace 
namespace sdds
{
	// reservation class 
	class Reservation
	{
		// all must be public, other modules will not be able to access and see these members 
		// public 
	public:

		// array of characters 
		std::string reservation_id;

		// name of reservation 
		std::string reservation_name;

		// used to send confirmation 
		std::string reservation_email;

		// number of people attending the party 
		unsigned int reservation_attendes;

		// which day the party is coming 
		unsigned int party_day;

		// which hour of the day the party is coming 
		unsigned int party_hour;

		// default constructor 
		Reservation();

		// constructor thats responsible for extracting info 
		Reservation(const std::string& res);

		// insertion operator (for displaying info in specified format)
		friend std::ostream& operator<<(std::ostream& os, const Reservation& reservation);
	};
}
#endif