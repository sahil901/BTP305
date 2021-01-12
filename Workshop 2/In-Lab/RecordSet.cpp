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

// header files 
#include <iostream> // cin & cout 
#include <string>
#include <fstream>
#include "RecordSet.h" // including headerfile 
using namespace std; 

// sdds namespace 
namespace sdds
{
	// no-arg constructor
	RecordSet::RecordSet()
	{
		// setting everything to null
		d_string = nullptr;
		n_record = 0;
	}

	// one-arg constructor
	RecordSet::RecordSet(const char* s)
	{
		// setting everything to null (do this because matrix had an issue)
		d_string = nullptr;
		n_record = 0;
		
		// local variable  
		unsigned int i = 0; 

		// from where characters are extracted 
		ifstream g_shakespeare(s);
		
		// where extracted line is stored 
		string shakespeare_line; 

		// if the file is good 
		if (g_shakespeare.good())
		{
			// while the file is not at the end of the file 
			while (!g_shakespeare.eof())
			{
				// extract characters with delimiter of single space 
				std::getline(g_shakespeare, shakespeare_line, ' ');
				
				// increment (go through characters)
				n_record++;
			}

			// setting d_string to a new string of index n_record
			d_string = new string[n_record];
			
			// increment (go through characters)
			n_record++;

			// clear the file 
			g_shakespeare.clear();

			// setting position of next character to be extracted 
			g_shakespeare.seekg(0);

			// while extracting characters with delimiter of single space 
			while (std::getline(g_shakespeare, shakespeare_line, ' '))
			{
				// setting d_string at index a to shakespeare_words
				d_string[i] = shakespeare_line;
				
				// increment (go through characters)
				i++;
			}
			
			// decrement (get rid of space located at end of file )
			n_record--;
			
			// close the file 
			g_shakespeare.close();
		}
	}

	// copy constructor
	RecordSet::RecordSet(const RecordSet& s)
	{
		// set d_string to nullptr 
		d_string = nullptr;
		*this = s;
	}

	// copy assignment operator 
	RecordSet& RecordSet:: operator=(const RecordSet& s)
	{
		if (this != &s)
		{
			// deallocate the memory assocaited with d_string
			delete[] d_string;

			// copy content of n_record into new object
			n_record = s.n_record;

			// allocate dynamic memory 
			d_string = new string[n_record];

			// iterate through for loop
			for (int i = 0; i < n_record; i++)
			{
				// copy content of d_string at index i into new object at indiex i 
				d_string[i] = s.d_string[i];
			}
		}
		return *this;
	}

	// destructor 
	RecordSet::~RecordSet()
	{
		// dealloactes the memory that associated with d_string
		delete[] d_string;
	}

	// query which returns # of records stored in current obj 
	size_t RecordSet::size() const
	{
		return n_record;
	}

	// query which returns record at the index recieved 
	string RecordSet::getRecord(size_t i) const
	{
		// if index is null then return empty string 
		if (d_string == nullptr)
		{
			// empty string 
			return "";
		}
		// else return the record at the index recieved 
		else
		{
			// returning record at index i 
			return d_string[i];
		}
	} 
}