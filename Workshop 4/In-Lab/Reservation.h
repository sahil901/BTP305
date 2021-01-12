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

// include header files 
#ifndef SDDS_RESERVATIONS_H
#define SDDS_RESERVATIONS_H
#include <string>

// sdds namespace 
namespace sdds
{
	// reservation class 
	class Reservation
	{
		std::string reservation_id; // array of characters
		std::string name_of_reservation; // name of the person with the reservation 
		std::string email; // can be used to send confirmation that reservation can be honored or not
		unsigned int number_of_people; // amount of people attending 
		unsigned int day; // when party expected to come 
		unsigned int hour; // when party expected to come 
		friend std::ostream& operator<<(std::ostream& os, const Reservation& s); // friend insertion operator 

		// public 
	public:
		Reservation(); // default constructor 
		Reservation(const std::string& m_res); // constructor that receives reservation as string
	};
}
#endif // !SDDS_RESERVATIONS_H
