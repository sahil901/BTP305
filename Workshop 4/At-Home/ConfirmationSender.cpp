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
#include <iostream>
#include "ConfirmationSender.h"
#include "Reservation.h"
using namespace std; 

// sdds namesapce 
namespace sdds
{
	// constructor
	// setting everything to empty state 
	ConfirmationSender::ConfirmationSender()
	{
		t_res = nullptr; 
		num_res = 0;
	}

	// destructor 
	// deallocates everything
	ConfirmationSender::~ConfirmationSender()
	{
		delete[] t_res; 
	}

	// add address of reservation res to array
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		// temp array 
		const Reservation** t_a = nullptr; 

		// check 
		bool check = false; 

		// iterate through 
		for (size_t i = 0; i < num_res; i++)
		{
			// if array index is equal to the reference of the current obj do the following 
			if (t_res[i] == &res)
			{
				check = true;
				break; 
			}
		}

		// do the following if conditions met 
		if (check == false)
		{
			// allocating new dynamic memory 
			t_a = new const Reservation * [num_res + 1];

			// iterate through 
			for (size_t i = 0; i < num_res; i++)
			{
				// assign the temporary array to the dynamically allocated array of pointers 
				t_a[i] = t_res[i];
			}

			// set the temporary array at index of number of people reserved to current object
			t_a[num_res] = &res; 

			// increment the dynamically allocated array of pointers 
			num_res++; 

			// deallocate the memory for the dynamically allocated array of pointers 
			delete[] t_res;

			// assign the dynamically allocated array of pointers to the temporary array 
			t_res = t_a;

			// set the temporary array to null 
			t_a = nullptr; 
		}
		return *this; 
	}

	// remove address of reservation res from array 
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		// temp array 
		const Reservation** t_a = nullptr;

		// check 
		bool check = false;

		// iterate through 
		for (size_t i = 0; i < num_res; i++)
		{
			// if array index is equal to the reference of the current obj do the following 
			if (t_res[i] == &res)
			{
				// set the dynamically allocated array of pointers to null 
				t_res[i] = nullptr; 

				// set people reserved to index i 
				num_res = i;
			}

			// do the following if conditions met 
			if (check == true)
			{
				// iterate through 
				for (size_t i = 0; i < num_res; i++)
				{
					// assign the temporary array to the dynamically allocated array of pointers 
					t_a[i] = t_res[i];
				}

				// decrement the dynamically allocated array of pointers 
				num_res--;

				// deallocate the memory for the dynamically allocated array of pointers 
				delete[] t_res;

				// assign the dynamically allocated array of pointers to the temporary array 
				t_res = t_a;

				// set the temporary array to null 
				t_a = nullptr;
			}
		}
		return *this;
	}

	// copy constructor 
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& s)
	{
		// setting attributes to empty 
		t_res = nullptr;
		num_res = 0;

		// copying into s 
		*this = s;
	}

	// copy assignment operator 
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& s)
	{
		// if this is not a reference of current object do following
		if (this != &s)
		{
			// if the object and current object are the same, memory will be deallocated 
			if (num_res == s.num_res)
			{
				delete[] t_res;
			}

			// assigning the number of people reserved to a local object 
			num_res = s.num_res;

			// if array of pointers i not null then do following 
			if (s.t_res != nullptr)
			{
				// allocating new dynamic memory 
				t_res = new Reservation const* [num_res];

				// iterate through 
				for (size_t i = 0; i < num_res; i++)
				{
					// assign the temporary array to the dynamically allocated array of pointers 
					t_res[i] = s.t_res[i];
				}
			}
			
			// else make it null
			else
			{
				t_res = nullptr;
			}
		}
		return *this; 
	}

	// move constructor 
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& s)
	{
		// setting attributes to empty 
		// same as copy constructor 
		t_res = nullptr;
		num_res = 0;

		*this = std::move (s);
	}

	// move assignment operator 
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& s)
	{
		// if this is not a reference of current object do following
		if (this != &s)
		{
			// setting t_res into current object 
				// and setting it to null
			t_res = s.t_res;
			s.t_res = nullptr;

			// setting num_res into the current object 
				// and setting it to null
			num_res = s.num_res;
			s.num_res = 0;
		}
		return *this;
	}

	// friend inseration operator 
		// prints info in specified format 
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& s)
	{
		// creating a local variable for the dashes
		string dashes_for_ouput = "--------------------------"; 

		// output dashes & specified text in specified format 
		os << dashes_for_ouput << endl;
		os << "Confirmations to Send" << endl; 
		os << dashes_for_ouput << endl;

		// if current object is empty then ouput following 
		if (s.num_res == 0)
		{
			os << "The object is empty!" << endl;
			os << dashes_for_ouput << endl;
		}

		// else iterate through reservations 
		else
		{
			// iterate through 
			for (size_t i = 0; i < s.num_res; i++)
			{
				os << *s.t_res[i];
			}

			// output dashes 
			os << dashes_for_ouput << endl;
		}
		return os; 
	}
}