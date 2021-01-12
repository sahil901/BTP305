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
#include "Car.h"

using namespace std;

namespace sdds
{
	Car::Car(std::istream& is)
	{
		string n;
		std::getline(is, n);
		std::stringstream ss(n);
		std::getline(ss, maker, ',');
		maker = trim(maker);
		std::getline(ss, m_condition, ',');
		m_condition = trim(m_condition);
		if(m_condition == "n" || m_condition == "N")
		{
			m_condition = "new";
		}
		else if (m_condition == "b" || m_condition == "B")
		{
			m_condition = "broken";
		}

		string speed;
		std::getline(ss, speed);
		speed = trim(speed);
		m_topSpeed = std::stod(speed);
	}

	std::string Car::condition() const
	{
		return m_condition;
	}

	double Car::topSpeed() const
	{
		return m_topSpeed;
	}

	void Car::display(std::ostream& out) const
	{
		out << "| ";
		out << setw(10) << right << maker << " | ";
		out << setw(6) << left << m_condition << " | ";
		out << setw(6) << fixed << setprecision(2) << m_topSpeed << " |" << endl;
	}

	std::string Car::trim(std::string str, const std::string& chars)
	{
		str.erase(0, str.find_first_not_of(chars));
		str.erase(str.find_last_not_of(chars) + 1);
		return str;
	}
}