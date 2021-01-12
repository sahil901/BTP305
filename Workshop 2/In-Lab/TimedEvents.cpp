/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: October/3rd/2020
Date Due: October/4th/2020
Prof Name: Cornel Barna
Class Section: NBB
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// header files 
#include <iostream> // cin & cout 
#include <string> 
#include "TimedEvents.h" // include the header file 
	// Note: chrono is included in header file 
using namespace std; 

// sdds namespace 
namespace sdds 
{
	// default constructor 
	TimedEvents::TimedEvents()
	{
		// setting to empty string 
		count[0].e_name = "";
		count[0].unit_time = "";
	}

	// starts timer for startClock
	void TimedEvents::startClock()
	{
		t_start = std::chrono::steady_clock::now();
	}

	// stops timer for event 
	void TimedEvents::stopClock()
	{
		t_end = std::chrono::steady_clock::now();
	}

	// recieves address of string which holds name of event 
	void TimedEvents::recordEvent(const char* s)
	{
		// sets name to s 
		count[current_record].e_name = s; 

		// utilizes nanoseconds for the time 
		count[current_record].unit_time = "nanoseconds";

		// subtracts the end time to the start time to find duration 
		count[current_record].e_duration = std::chrono::duration_cast <std::chrono::nanoseconds>(t_end - t_start); 
		
		// increments 
		current_record++; 
	}

	// friend insertion operator 
	std::ostream& operator<<(std::ostream& os, TimedEvents& p)
	{
		os << "--------------------------" << endl;
		os << "Execution Times:" << endl; 
		os << "--------------------------" << endl; 

		// formatting of output 
		for (int i = 0; i < p.current_record; i++)
		{
			os.setf(std::ios::left);
			os.width(20);
			os << p.count[i].e_name << " ";
			os.setf(std::ios::right);
			os.width(12); 
			os << p.count[i].e_duration.count() << " " << p.count[i].unit_time << std::endl;
			os.unsetf(std::ios::right); 
		}
		os << "--------------------------" << endl; 
		return os; 
	}
}