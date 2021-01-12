/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: October/24th/2020
Date Due: October/25th/2020
Prof Name: Cornel Barna
Class Section: NBB
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// File Headers 
#ifndef _SDDS_COLLECTION_H
#define _SDDS_COLLECTION_H
#include <iostream>
#include <string>

// sdds namespace 
namespace sdds
{
	// Type T template 
	template<typename T>

	// collection class
	class Collection
	{
		// collection name 
		std::string c_name;

		// type T dynamically allocated array 
		T* a_item;

		// array size 
		size_t a_size; 

		// pointer to function 
		void (*e_observe)(const Collection<T>&, const T&);

		// public
	public:

		// constructor 
		Collection(std::string name)
		{
			// set name of collection to parameter 
			c_name = name; 

			// all attributes to default value 
			a_item = nullptr;
			e_observe = nullptr;
			a_size = 0; 	
		}

		// destructor 
		~Collection()
		{
			// if not null then do following 
				// deallocate mem and set null
			if (a_item != nullptr)
			{
				delete[] a_item;
				a_item = nullptr; 
			}
		}

		// query that returns the name of the collection
		const std::string& name() const
		{
			return c_name; 
		}

		// query that returns the number of items in the collection
		size_t size() const
		{
			return a_size; 
		}

		// store address of callback function... 
		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			e_observe = observer;
		}

		// adds copy of item to collection... 
		Collection<T>& operator+=(const T& item)
		{
			bool add_c = true; 

			// iterate through 
			for (size_t i = 0; i < a_size; i++)
			{
				if (a_item[i].title() == item.title())
				{
					add_c = false;
				}
			}

			// if true then do following 
			if (add_c)
			{
				T* temporary = new T[a_size + 1];

				// iterate through 
				for (size_t i = 0; i < a_size; i++)
				{
					temporary[i] = a_item[i];
				}

				// increment
				++a_size; 

				// deallocte array 
				delete[] a_item; 
				a_item = temporary; 
				a_item[a_size - 1] = item;

				// not null then do following 
				if (e_observe != nullptr)
				{
					e_observe(*this, item);
				}
			}
			return *this; 
		}

		// return item at index
		T& operator[](size_t idx) const
		{
			// if index out of range then do following 
			if (idx >= a_size || idx < 0)
			{
				// throw exception message 
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(a_size) + "] items.");
			}

			// else do the following 
			else
			{
				// return the item in the array at specified index
				return a_item[idx];
			}
		}

		// returns address of the item with the title 
		T* operator[](std::string title) const
		{
			// iterate through 
			for (size_t i = 0; i < a_size; ++i)
			{
				// if title is equal to the title in array then output the title in the array
				if (a_item[i].title() == title)
				{
					return &a_item[i];
				}
			}
			return nullptr; 
		}
	};

	// Type T template 
	template<typename T>

	// insertion operator 
	std::ostream& operator <<(std::ostream& os, const Collection<T>& s)
	{
		// iterae through 
		for (size_t i = 0; i < s.size(); ++i)
		{
			os << s[i];
		}
		return os;
	}
}
#endif // !_SDDS_COLLECTION_H