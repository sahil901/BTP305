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


#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include"Vehicle.h"

	namespace sdds
{
	class Car : public Vehicle
	{
		std::string maker;
		std::string m_condition;
		double m_topSpeed;

	public:
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		std::string trim(std::string str, const std::string& chars = "\t\n\v\f\r ");
	};
}

#endif