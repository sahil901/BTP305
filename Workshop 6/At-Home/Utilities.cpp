/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date Started: November/10th/2020
Date of completion: November/12th/2020
Date Due: November/14th/2020
Prof Name: Cornel Barna
Class Section: NBB
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include "Utilities.h"
#include "Car.h"
#include"Racecar.h"

using namespace std;

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		std::string n;
		std::getline(in, n);
		std::stringstream ss(n);
		string type;
		std::getline(ss, type, ',');
		type.erase(0, type.find_first_not_of("\t\n\v\f\r "));
		type.erase(type.find_last_not_of("\t\n\v\f\r ") + 1);
		if (type == "c" || type == "C")
		{
			return new Car(ss);
		}
		else if (type == "r" || type == "R")
		{
			return new Racecar(ss);
		}
		else if (type == "") {
			return nullptr;
		}
		else
		{
			std::string str = "Unrecognized record type: [" + type + "]";
			throw str;
		}
		
	}
}