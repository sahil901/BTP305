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
#ifndef _SDDS_PAIR_H
#define _SDDS_PAIR_H
#include <iostream>

// sdds namespace 
namespace sdds
{
	// template with specified parameters 
	template<typename K, typename V>

	// Pair class
	class Pair
	{
		// type of key 
		K t_key;

		// type of value 
		V t_value;

		// public
	public:

		// default constructor 
		Pair() : t_key{}, t_value{}
		{

		}

		// copies values specified by params into instance variables 
		Pair(const K& key, const V& value)
		{
			t_key = key;
			t_value = value;
		}

		// return key component
		const K& key() const
		{
			return t_key;
		}

		// return value component 
		const V& value() const
		{
			return t_value;
		}

		// inserts key and value in specified format
		// PART 2: to make it have inclusion polymorphism we add virtual 
		virtual void display(std::ostream& os) const
		{
			os << t_key << " : " << t_value << std::endl;
		}
	};

	// template with specified parameters 
	// adds template to free helper 
	// need again because its outside the class
	template<typename K, typename V>

	// class display on pair and inserts into stream 
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair)
	{
		pair.display(os);
		return os;
	}
}
#endif // !_SDDS_PAIR_H