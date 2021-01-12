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
#ifndef _SDDS_RECORDSET_H
#define _SDDS_RECORDSET_H
#include <iostream> // cin & cout
#include <string> // use string

//sdds namespace 
namespace sdds
{
	// RecordSet class
	class RecordSet
	{
		// dynamically allocated array 
		std::string* d_string;

		// number of strings currently stored 
		int n_record;

		// member functions 
			// public
		public:

		// no-arg constructor
		RecordSet();

		// one-arg constructor
		RecordSet(const char*);

		// copy constructor
		RecordSet(const RecordSet&);

		// copy assignment operator 
		RecordSet& operator=(const RecordSet&);

		// destructor 
		~RecordSet();

		// query which returns # of records stored in current obj 
		size_t size() const;

		// query which returns record at the index recieved 
		std::string getRecord(size_t) const;
	};
}
#endif // !_SDDS_RECORDSET_H