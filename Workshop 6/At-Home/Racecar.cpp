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
#include <vector>

#include "Racecar.h"

using namespace std;

namespace sdds
{
	Racecar::Racecar(std::istream& in):Car(in)
	{
		string n;
		std::getline(in, n);
		std::stringstream ss(n);
		string booster;
		std::getline(ss, booster);
		booster = trim(booster);
		m_booster = std::stod(booster);
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*" ;
	}
	double Racecar::topSpeed() const
	{
		
		return Car::topSpeed() * (1 + m_booster);
	}
}