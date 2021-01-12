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
		desc = nullptr;
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

		// outputing in specified format
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

	// receives array of characters and stores information in current instance 
	void Event::setDescription(const char* s)
	{
		this->midnight_sec = g_sysClock;
		
		// if not null then 
		if ((s != nullptr)) 
		{
			unsigned int a = strlen(s);
			
			if (desc == nullptr) 
			{
				desc = new char[a + 1];
			}

			// else do the following 
			else
			{
				delete[] desc; 
				desc = new char[a + 1];
			}
			
			strncpy(desc, s, a);
			desc[a] = '\0'; // null terminator 
		}
		
		// else set desc to nullptr 
		else 
		{
			desc = nullptr;
		}
	}

	// destructor 
	Event::~Event()
	{
		// deallocating memory for desc 
		delete[] desc; 
	}

	// copy constructor 
	Event::Event(const Event& c)
	{
		desc = nullptr;
		*this = c;
	}

	// copy assignment opertor 
	Event& Event::operator=(const Event& d)
	{
		if (this != &d)
		{
			// shallow copy non-resource variables
			midnight_sec = d.midnight_sec; 

			// if desc is not null then do the following 
			if (desc != nullptr) 
			{
				// deallocate previously allocated dynamic memory
				delete[] desc;
			}
			
			// if not null then do the following 
			if (d.desc != nullptr)
			{
				unsigned int a = strlen(d.desc); // find the size of the string 
				desc = new char[a + 1];
				
				for (unsigned int i = 0; i < a; i++)
				{
					desc[i] = d.desc[i]; // set the index of i from desc to the local obj of index i  
				}
				desc[a] = '\0'; // null terminator 
			}
		}
		return *this; 
	}
}