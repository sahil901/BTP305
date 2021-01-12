/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: October/10th/2020
Date Due: October/11th/2020
Prof Name: Cornel Barna
Class Section: NBB
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// File Headers 
#ifndef _SDDS_SETSUMMABLE_H
#define _SDDS_SETSUMMABLE_H
#include <iostream>
#include"Set.h"
using namespace std;

// sdds namespace 
namespace sdds 
{
	// template with specified parameters 
	template<typename T, unsigned int N> 

	// deriving class template 
	class SetSummable : public Set<T, N> 
	{ 
		// public 
	public: 

		//  accumulates all the elements in the collection
		T accumulate(const std::string& filter) const 
		{
			// initalizing the accumulator 
			T add(filter);

			// iterating over the collection 
			for (size_t i = 0u; i < N; ++i) 
			{  
				if (filter == (*this)[i].key())
				{
					// adding each item's contribution to the accumulator
					add += (*this)[i];
				}		
			}

			// return the accumulator to the client
			return add; 
		}
	};
}
#endif