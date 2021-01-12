/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: September/23rd/2020
Date Due: September/27th/2020
Prof Name: Cornel Barna
Class Section: NBB
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// File Header(s)
#ifndef _SDDS_EVENT_H
#define _SDDS_EVENT_H
#include <iostream>

// global variable, stores only postive integers. 
	// since its global it has to be declared outside the namespace with extern 
	// unsigned because we only want to store postive integers 
extern unsigned int g_sysClock;

//sdds namespace
namespace sdds
{
	// event class 
	class Event
	{
		// c-style terminated string of up to 128 characters 
		char* desc;

		// value of clock repersented by integer (has to be postive) 
		unsigned int midnight_sec;

		// explicitaly put in private member
		static unsigned int counter;

		// public 
	public:
		Event(); // default constructor 
		void display() const; // query that displays to screen content of instance in specified format
		void setDescription(const char*); // modifier that receives parameter an array of characters
		Event(const Event&); // copy constructor
		Event& operator=(const Event&); // copy assignment opertor 
		~Event(); // destructor 
	};
}
#endif // !_SDDS_EVENT_H