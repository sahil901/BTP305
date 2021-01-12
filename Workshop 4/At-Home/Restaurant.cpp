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
#include "Restaurant.h"
#include "Reservation.h"
using namespace std;

// sdds namespace 
namespace sdds
{
	// constructor
	// sets everything to empty state 
	Restaurant::Restaurant()
	{
		res_array = nullptr;
		res_num = 0;
	}

	// destructor 
	// deallocates everything
	Restaurant::~Restaurant()
	{
		delete[] res_array;
	}

	// constructor which stores copies 
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
	{
		// if reservations is null and cnt is 0 then do the following 
		if (reservations != nullptr && cnt > 0)
		{
			// creating new instances 
			res_array = new Reservation[cnt];
			res_num = cnt; 

			// iterating through and setting all objects to the current objects 
			for (size_t i = 0; i < cnt; i++)
			{
				this->res_array[i].reservation_id = reservations[i]->reservation_id;
				this->res_array[i].reservation_name = reservations[i]->reservation_name;
				this->res_array[i].reservation_email = reservations[i]->reservation_email;
				this->res_array[i].reservation_attendes = reservations[i]->reservation_attendes;
				this->res_array[i].party_day = reservations[i]->party_day;
				this->res_array[i].party_hour = reservations[i]->party_hour;
			}
		}
	}
	
	// copy constructor 
	Restaurant::Restaurant(Restaurant& s)
	{
		// setting attributes to empty 
		res_array = nullptr;
		res_num = 0;

		// copying into s 
		*this = s;
	}

	// copy assignment operator 
	Restaurant& Restaurant::operator=(const Restaurant& s)
	{
		// if this is not a reference of current object do following
		if (this != &s)
		{
			// if object equals to current obj then deallocate memory of array
			if (res_num == s.res_num)
			{
				delete[] res_array; 
			}

			// assigning the reservations made reserved to a local object 
			res_num = s.res_num; 

			// if the local object is not null then do the following
			if (s.res_array != nullptr)
			{
				// formulating a new instance 
				res_array = new Reservation[res_num]; 

				// iterating through and setting all objects to the current objects 
				for (size_t i = 0; i < res_num; ++i)
				{
					this->res_array[i].reservation_id = s.res_array[i].reservation_id;
					this->res_array[i].reservation_name = s.res_array[i].reservation_name;
					this->res_array[i].reservation_email = s.res_array[i].reservation_email;
					this->res_array[i].reservation_attendes = s.res_array[i].reservation_attendes;
					this->res_array[i].party_day = s.res_array[i].party_day;
					this->res_array[i].party_hour = s.res_array[i].party_hour;
				}
			}

			// else make the array to null 
			else
			{
				res_array = nullptr; 
			}
		}
		return *this;

	}

	// move constructor 
	Restaurant::Restaurant(Restaurant&& s)
	{
		// setting attributes to empty 
			// same as copy constructor 
		res_array = nullptr; 
		res_num = 0;

		*this = move(s);
	}

	// move assignment operator 
	Restaurant& Restaurant::operator=(Restaurant&& s)
	{
		// if this is not a reference of current object do following
		if (this != &s)
		{
			// setting res_array into current object 
				// and setting it to null
			res_array = s.res_array;
			s.res_array = nullptr;

			// setting num_res into the current object 
				// and setting it to null
			res_num = s.res_num;
			s.res_num = 0;
		}
		return *this; 
	}

	// return number of reservations 
	size_t Restaurant::size() const
	{
		return res_num; 
	}

	// friend helper function 
	// prints info in specified format 
	ostream& operator<<(std::ostream& os, const Restaurant& restaurant)
	{
		 // creating a local variable for the dashes
		 string lines = "--------------------------"; 

		// if the object array is null ouput the following 
		if (restaurant.res_array == nullptr)
		{
			// output dashes & specified text in specified format 
			os << lines << endl;
			os << "Fancy Restaurant" << endl;
			os << lines << endl;
			os << "The object is empty!" << endl;
			os << lines << endl;
		}

		// else do the following output
		else
		{
			// output dashes & specified text in specified format 
			os << lines << endl;
			os << "Fancy Restaurant" << endl;
			os << lines << endl;

			// iterate through 
			for (size_t i = 0; i < restaurant.res_num; i++)
			{
				// put here to minimize code repetition
				cout << "Reservation " << restaurant.res_array[i].reservation_id << ": " << setw(10) << right << restaurant.res_array[i].reservation_name << "  " << setw(24) << left << "<" + restaurant.res_array[i].reservation_email + ">";

				// between 6 and 9, serve breakfast 
				if (restaurant.res_array[i].party_hour >= 6 && restaurant.res_array[i].party_hour <= 9)
				{
					cout << "Breakfast on day ";  
				}

				// between 11 and 15 (3), serve lunch 
				else if (restaurant.res_array[i].party_hour >= 11 && restaurant.res_array[i].party_hour <= 15)
				{
					cout << "Lunch on day "; 
				}

				// between 17 (5) and 21 (9), serve dinner  
				else if (restaurant.res_array[i].party_hour >= 17 && restaurant.res_array[i].party_hour <= 21)
				{
					cout << "Dinner on day ";
				}

				// only drinks served. kitchen is close 
				else
				{
					cout << "Drinks on day ";  
				}

				// put here to minimize code repetition
				cout << restaurant.res_array[i].party_day << " @ " << restaurant.res_array[i].party_hour << ":00" << " for " << restaurant.res_array[i].reservation_attendes << " people." << '\n';
			}

			// output the dashes 
			os << lines << endl;
		}
		return os; 
	}
}