/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: October/7th/2020
Date Due: October/11th/2020
Prof Name: Cornel Barna
Class Section: NBB
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// File Headers 
#ifndef _SDDS_SET_H
#define _SDDS_SET_H

// sdds namespace 
namespace sdds
{
	// template with specified parameters 
	template <class T, int N>

	// Set class
	class Set
	{
		// statically allocated array 
		T c_array[N]; 

		// current number of elements 
		size_t c_elements = 0; 

		// public 
	public: 

		// return current number of elements 
		size_t size() const
		{
			return c_elements;
		}

		// return element at index  
		const T& operator[](size_t idx) const
		{
			return c_array[idx];
		}

		// if list has space for another element add a copy of it 
		void operator+=(const T& item)
		{
			// if capacity of collection is greater than numer of elements 
			if (c_elements < N)
			{
				c_array[c_elements] = item;
				c_elements++;
			}
		}
	};
}
#endif // ! _SDDS_SET_H