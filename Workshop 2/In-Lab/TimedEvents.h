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

// File Headers 
#ifndef _SDDS_TIMEDEVENTS_H
#define _SDDS_TIMEDEVENTS_H
#include <iostream> // cin and cout
#include <chrono> // lets us use chrono 

// sdds namespace
namespace sdds
{
	// maximum number of record objects 
	const int max_obj = 7;

	//TimedEvents class
	class TimedEvents
	{
		// # of records currently stored
		int current_record = 0;

		// start time & end time for current event 
			// start time
		std::chrono::time_point<std::chrono::steady_clock> t_start;
			// end time 
		std::chrono::time_point<std::chrono::steady_clock> t_end;

		// anonymous struct (not named)
		struct
		{
			// string with event name
			std::string e_name;

			// string with predefined unit of time
			std::string unit_time;

			// duration of recorded event
			std::chrono::steady_clock::duration e_duration;
		} count[max_obj]; // makes struct an array 

	// class members 
		// public
	public:
		// constructor 
		TimedEvents();

		// starts timer for event
		void startClock();

		// stops timer for event 
		void stopClock();

		// recieves address of string which holds name of event 
		void recordEvent(const char*);

		// friend insertion operator
		friend std::ostream& operator<<(std::ostream&, TimedEvents&);
	};
}
#endif // !_SDDS_TIMEDEVENTS_H