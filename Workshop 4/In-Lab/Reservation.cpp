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
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Reservation.h"

// sdds namespace 
namespace sdds
{
	// default constructor 
	Reservation::Reservation()
	{
		// strings 
		reservation_id = "";
		name_of_reservation = "";
		email = "";

		// unsigned ints 
		number_of_people = 0;
		day = 0;
		hour = 0;
	}

	Reservation::Reservation(const std::string& m_res)
	{
		std::string str = m_res;

		// reservation id 
		str.erase(remove(str.begin(), str.end(), ' '), str.end()); // removes all spaces in the string
		reservation_id = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);

		// reservation name 
		name_of_reservation = str.substr(0, str.find(","));
		str.erase(0, str.find(",") + 1);

		// email 
		email = str.substr(0, str.find(","));
		str.erase(0, str.find(",") + 1);

		// number of people
		number_of_people = stoi(str);
		str.erase(0, str.find(",") + 1);

		// day
		day = std::stoi(str);
		str.erase(0, str.find(",") + 1);

		// hour 
		hour = stoi(str);
		str.erase(0, str.find(",") + 1);
	}

	// friend insertion operator (all times for the kitchen are inclusive...)
	std::ostream& operator<<(std::ostream& os, const Reservation& s)
	{
		// hour between 6AM & 9AM, kitchen serves breakfast
		if (s.hour >= 6 && s.hour <= 9)
		{
			// Reservation 
			std::cout << "Reservation " << s.reservation_id << ": "

				// name on reservation should be printed on field of size 10, aligned to right
				<< std::setw(10) << std::right << s.name_of_reservation << "  "

				// email on reservation (including the characters < and >) should be printed on field size 20, aligned to left
				<< std::setw(20) << std::left << "<" + s.email + ">"

				// Breakfast
				<< "    Breakfast on day " << s.day << " @ "
				<< s.hour << ":00" << " for "
				<< s.number_of_people << " people." << std::endl; // operator should insert endline character before exiting
		}

		// hour between 11AM & 3PM, kitchen serves lunch
		else if (s.hour >= 11 && s.hour <= 15)
		{
			std::cout << "Reservation " << s.reservation_id << ": "

				// name on reservation should be printed on field of size 10, aligned to right
				<< std::setw(10) << std::right << s.name_of_reservation << "  "

				// email on reservation (including the characters < and >) should be printed on field size 20, aligned to left
				<< std::setw(20) << std::left << "<" + s.email + ">"

				// Lunch
				<< "    Lunch on day " << s.day
				<< " @ " << s.hour << ":00" << " for "
				<< s.number_of_people << " people." << std::endl; // operator should insert endline character before exiting
		}

		// hour between 5PM and 9PM, kitchen serves dinner
		else if (s.hour >= 17 && s.hour <= 21)
		{
			std::cout << "Reservation " << s.reservation_id << ": "

				// name on reservation should be printed on field of size 10, aligned to right
				<< std::setw(10) << std::right << s.name_of_reservation << "  "

				// email on reservation (including the characters < and >) should be printed on field size 20, aligned to left
				<< std::setw(20) << std::left << "<" + s.email + ">"

				// Dinner
				<< "    Dinner on day " << s.day
				<< " @ " << s.hour << ":00" << " for "
				<< s.number_of_people << " people." << std::endl; // operator should insert endline character before exiting
		}

		// any other time, kitchen closed... only drinks served 
		else
		{
			std::cout << "Reservation " << s.reservation_id << ": "

				// name on reservation should be printed on field of size 10, aligned to right
				<< std::setw(10) << std::right << s.name_of_reservation << "  "

				// email on reservation (including the characters < and >) should be printed on field size 20, aligned to left
				<< std::setw(20) << std::left << "<" + s.email + ">"

				// Drinks 
				<< "    Drinks on day " << s.day
				<< " @ " << s.hour << ":00" << " for "
				<< s.number_of_people << " people." << std::endl; // operator should insert endline character before exiting
		}
		return os;
	}
}