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
#include "Utilities.h"
#include "Car.h"

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
		if (type == "c")
		{
			return new Car(ss);
		}
		return nullptr;
	}
}