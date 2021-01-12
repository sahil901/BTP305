/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date Started: November/15th/2020
Date of completion: November/24th/2020
Date Due: November/28th/2020
Prof Name: Cornel Barna
Class Section: NBB
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// File Headers
#include "LineManager.h"

// custom constructor 
LineManager::LineManager(const std::string& line, std::vector<Workstation*>& work, std::vector<CustomerOrder>& order)
{
	// resizing container 
	AssemblyLine.resize(work.size());

	// resizing queue
	ToBeFilled.resize(order.size());

	// filling order from start to finish 
	std::move(order.begin(), order.end(), ToBeFilled.begin());

	// call assembly from start to finish 
	std::move(work.begin(), work.end(), AssemblyLine.begin());

	// retreving size of order 
	m_cntCustomerOrder = order.size();

	// read contents  
	std::ifstream file(line); 

	// file cany open then throw message
	if (!file)
	{
		throw "Error Opening File!"; 
	}

	// local string used to extract
	std::string extract;

	// starting point 
	size_t start = 0;

	// local bool 
	bool state = true;

	// obj frm Utilites module
	Utilities local_obj_util;

	// not at end of file do following
	while (!file.eof())
	{
		// grab line and put into local string 
		std::getline(file, extract); 

			// extract info 
		std::string first = local_obj_util.extractToken(extract, start, state);
		std::string second = local_obj_util.extractToken(extract, start, state);

		// iterating in assembly 
		for (size_t i = 0; i < AssemblyLine.size(); i++)
		{
			// if first is same as assembly as specified index then iterate again 
			if (AssemblyLine[i]->getItemName() == first)
			{
				// iterating 
				for (size_t z = 0; z < AssemblyLine.size(); z++)
				{
					// if second is same as assembly as specified index then go onto next
					if (AssemblyLine[z]->getItemName() == second)
						AssemblyLine[i]->setNextStation(*AssemblyLine[z]);
				}
			}
		}
	}
	file.close(); 
}


 size_t LineManager::statrep() const
{
	// creating a local int, bool,
	size_t local = 0;
	bool check = false;

	// iterate though the assembly line 
	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		// setting the int to the index
		local = i;

		// iterate though the assembly line 
		for (size_t z = 0; z < AssemblyLine.size(); z++)
		{
			// if not nullptr and doesn't meet the compare criteria then set to false 
			if (AssemblyLine[z]->getNextStation() != nullptr && AssemblyLine[i]->getItemName().compare(AssemblyLine[z]->getNextStation()->getItemName()) == 0)
			{
				local = check;
			}
		}

		// if not false then break 
		if (local != check)
		{
			break;
		}
	}
	return local; 
}

// perform one cycle of operations on assemly line 
bool LineManager::run(std::ostream& os)
{
	// creating the iteration num and giving it a default value 
	static size_t iterate_num = 1;

	// creating a temp customer obj
	CustomerOrder cust_obj;
	
	// formatted output
	os << "Line Manager Iteration: " << iterate_num << std::endl;

	// iterate each time
	iterate_num++;

	// if there are customer objs in queue then do the following 
	if (!ToBeFilled.empty())
	{
		// calling my own created function for cleaner code  
		size_t own = statrep();
	
		// move to the front of the assembly line and front fill
		*AssemblyLine[own] += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	// iterating through assembly line while a cycle is being ran on it 
	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		AssemblyLine[i]->runProcess(os);
	}
	
	// iterating through assembly line 
	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		if (AssemblyLine[i]->getNextStation() == nullptr)
		{
			// if element i passed via getIfcompleted then move to the completed orders
			if (AssemblyLine[i]->getIfCompleted(cust_obj))
			{
				Completed.push_back(std::move(cust_obj));
			}
		}

		// else take element i from the assembly line and put it through the move order function in workstation
		else
		{
			AssemblyLine[i]->moveOrder();
		}
	}

	// if all the customer orders have been filled then return true
	if (m_cntCustomerOrder == Completed.size())
	{
		return true;
	}

	// otherwise return false
	else
	{
		return false;
	}
}

// displays all the orders that were completed
void LineManager::displayCompletedOrders(std::ostream& os) const
{
	// iterating through the orders and displaying the completed ones 
	for (size_t i = 0; i < Completed.size(); i++)
	{
		Completed[i].display(os); 
	}
}

// display all stations on the assembly line in the order they were received from the client
void LineManager::displayStations() const
{
	// iterating through the orderfs and displaying the stations on the assembly line 
	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		AssemblyLine[i]->display(std::cout);

		// manual break
		if (i > 5)
		{
			break; 
		}
	}
}

// display all stations on the assembly line in the order they are linked 
void LineManager::displayStationsSorted() const
{
	// calling my own created function for cleaner code 
	size_t own = statrep();

	// set the index of assembly line to the pointer and then...
	const Workstation *l_stat = AssemblyLine[own];
	
	// while not nullptr 
	// display the pointer in the order its linked and get the next station from the workstation 
	while (l_stat != nullptr)
	{
		l_stat->display(std::cout);
		l_stat = l_stat->getNextStation();
	}
}
