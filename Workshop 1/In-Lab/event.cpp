/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: September/26th/2020
Prof Name: Cornel Barna
Class Section: NBB
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// File Header(s)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // strncpy
#include <iomanip> // setw 
#include "event.h"

using namespace std;

// defining g_sysClock and setting default value to 0
unsigned int g_sysClock = 0;

// sdds namespace
namespace sdds
{
	// declared and will be instantiated 
	unsigned int Event::counter;

	// default constructor
		// setting default values 
	Event::Event()
	{
		midnight_sec = 0;
		desc[0] = '\0' ;
		Event::counter = 1;
	}

	// displays time in specified format 
	void Event::display() const
	{
		// time calculation
		unsigned int t_hours = 0;
		unsigned int t_minutes = 0;
		unsigned int t_seconds = 0;

		// calculating hour 
		t_hours = midnight_sec / 3600;

		// calculating minutes 
		t_minutes = (midnight_sec - (t_hours * 3600)) / 60;

		// calculating seconds 
		t_seconds = (midnight_sec - (t_hours * 3600) - (t_minutes * 60));

		cout << setw(3) << setfill(' ') << counter++ << ". ";

		if (desc != nullptr && desc[0] != '\0') 
		{
			cout << setw(2) << setfill('0') << t_hours << ":" << setw(2) << setfill('0') << t_minutes << ":" << setw(2) << setfill('0') << t_seconds << " -> " << desc << endl;
		}
		else 
		{
			cout << "[ No Event ]" << endl;
		}
	}

	void Event::setDescription(const char* s)
	{
		this->midnight_sec = g_sysClock;
		if (s != nullptr || s != NULL) {
			memset(desc, 0, sizeof desc); // gets rid of buffer 
			strncpy(desc, s, strlen(s));
		}
		else {
			memset(desc, 0, sizeof desc); // gets rid of buffer 
			desc[0] = '\0';
		}
	}
}