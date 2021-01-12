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
#ifndef _SDDS_PAIRSUMMABLE_H
#define _SDDS_PAIRSUMMABLE_H
#include <iomanip>
#include <iostream>
#include"Pair.h"
using namespace std;

// sdds namespace 
namespace sdds
{ 
	// template with specified parameters
	template<typename K, typename V> 

	// deriving class template 
	class PairSummable : public Pair<K, V> 
	{
		// holds the initial value for a summation
		static V initial_val; 

		// holds the minimum field width
		static size_t min_width; 

		// public 
	public: 

		// default consturctor 
		PairSummable()
		{
		
		} 

		// calls the base class constructor passing two parameters
		PairSummable(const K& key, const V& value = initial_val) : Pair<K, V>(key, value)
		{
			if (min_width < key.size())
			{
				min_width = key.size();
			}
		}

		// receive a reference to an unmodifiable PairSummable object
		PairSummable<K, V>& operator+=(const PairSummable<K, V>& s)
		{
			// to add the value of the parameter to the value of the current object if both objects share the same key but not the address, and to return a reference to the current object.
			if (this != &s && this->key() == s.key())
			{
				*this = PairSummable(this->key(), this->value() + s.value());
			}	
			return *this;
		}

		// set alignment to specified info 
		void display(std::ostream& os) const
		{
			os << setw(min_width) << left;
			Pair<K, V>::display(os);
			os << right;
		}
	};

	// Specializations

	// initalize the static private member to 0... told to do it in "Static Private Members for PairSummable"
	template <typename K, typename V>
	size_t PairSummable<K, V>::min_width = 0;

	// initial value for summation should be an empty string ("")
	template<>
	std::string PairSummable<std::string, std::string>::initial_val = "";

	// initial value for summation should be 0
	template<>
	int PairSummable<std::string, int>::initial_val = 0;

	// function operator+=() should concatenate the values stored using , as a separator
	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& s)
	{
		// basically the same as the += operator that is stated above
		if (s.key() == this->key() && this != &s) 
		{
			// if value had no space then do this
			if (value() == "")
			{
				*this = PairSummable(this->key(), this->value() + s.value());
			}
				
			// else do this with a , seperator 
			else
			{
				*this = PairSummable(this->key(), this->value() + ", " + s.value());
			}
		}
		return *this;
	}
}
#endif