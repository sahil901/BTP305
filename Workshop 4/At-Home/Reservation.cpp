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
#include <iomanip>
#include <iostream>
#include <algorithm> // find 
#include "Reservation.h"
using namespace std;

// sdds namespace 
namespace sdds
{
	// default constructor 
		// setting everything to empty state 
	Reservation::Reservation()
	{
		reservation_id = "";
		reservation_name = "";
		reservation_email = "";
		reservation_attendes = 0;
		party_day = 0;
		party_hour = 0;
	}

	// constructor thats responsible for extracting info
		// NOTE TO SELF: can also create trim function
	Reservation::Reservation(const std::string& res)
	{
		// parameter cannot be manipulated without this 
		string s = res;

		// removes the spaces 
		s.erase(remove(s.begin(), s.end(), ' '), s.end());

		// First character all the way to colon
		reservation_id = s.substr(0, s.find(":"));

		// erases the space after colon 
		s.erase(0, s.find(":") + 1);

		// First character all the way to comma 
		reservation_name = s.substr(0, s.find(","));

		// erases the space after commas 
		s.erase(0, s.find(",") + 1);

		// First character all the way to comma
		reservation_email = s.substr(0, s.find(","));

		// removes the commas 
		s.erase(0, s.find(",") + 1);

		// parsing the int for amount of people attending party 
		reservation_attendes = stoi(s);

		// removes the commas 
		s.erase(0, s.find(",") + 1);

		// parsing the int for day of the party 
		party_day = stoi(s);

		// removes the commas 
		s.erase(0, s.find(",") + 1);

		// parsing the int for hour of the party 
		party_hour = stoi(s);

		// removes the commas 
		s.erase(0, s.find(",") + 1);
	}

	// insertion operator (for displaying info in specified format)
	std::ostream& operator<<(std::ostream& os, const Reservation& reservation)
	{
		// put here to minimize code repetition
		cout << "Reservation " << reservation.reservation_id << ": " << setw(10) << right << reservation.reservation_name << "  " << setw(20) << left << "<" + reservation.reservation_email + ">";

		// between 6 and 9, serve breakfast 
		if (reservation.party_hour >= 6 && reservation.party_hour <= 9)
		{
			cout << "    Breakfast on day ";  
		}

		// between 11 and 15 (3), serve lunch 
		else if (reservation.party_hour >= 11 && reservation.party_hour <= 15)
		{
			cout << "    Lunch on day ";  
		}

		// between 17 (5) and 21 (9), serve dinner  
		else if (reservation.party_hour >= 17 && reservation.party_hour <= 21)
		{
			cout << "    Dinner on day ";  
		}

		// only drinks served. kitchen is close 
		else
		{
			cout << "    Drinks on day "; 
		}

		// put here to minimize code repetition
		cout << reservation.party_day << " @ " << reservation.party_hour << ":00" << " for " << reservation.reservation_attendes << " people." << std::endl;
		return os;
	}
}