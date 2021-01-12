// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	size_t c_line = 0; 
	// get the books
	sdds::Book library[7];
	{
		// TODO: load the collection of books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the array "library"
		//       - lines that start with "#" are considered comments and should be ignored
	
		// places file as first argument and proccesses it 
		std::ifstream file(argv[1]);

		// if its not the file then output the following 
		if (!file) 
		{
			// output the error and message 
			std::cerr << "ERROR, File cannot be opened! Error in the following file [" << argv[1] << "].\n";
			return 1;
		}

		// local variable 
		std::string bo_ok;
		
		do 
		{
			// get the line from the file and place it in the local variable 
			std::getline(file, bo_ok);

			// if it is the file then do the following 
			if (file)
			{
				// if the first element is not # then do the following 
				if (bo_ok[0] != '#')
				{
					// increment through
					c_line++;
				}
			}
		} while (file);
		c_line = 0;

		// clear the buffer 
		file.clear();
		file.seekg(std::ios::beg);

		do 
		{
			// get the line from the file and place it in the local variable 
			std::getline(file, bo_ok);

			// if it is the file then do the following 
			if (file)
			{
				// if the first element is not # then do the following 
				if (bo_ok[0] != '#')
				{
					// store into the array 
					library[c_line] = sdds::Book(bo_ok);
					
					// increment through 
					c_line++;
				}
			}
		} while (file);
		
		// close the file 
		file.close();
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object
	auto lambda = [&, usdToCadRate, gbpToCadRate](Book& s)
	{
		// if the country is US then do the following 
		if (s.country() == "US")
		{
			// multiply the price and save it 
			s.price() *= usdToCadRate;
		}

		// if the country is UK and the year is between 1990 and 1999 then do the following 
		if (s.country() == "UK" && s.year() >= 1990 && s.year() <= 1999)
		{
			// multiply the price and save it 
			s.price() *= gbpToCadRate;
		}
		return s.price();
	};


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (unsigned int i = 0; i < 7; ++i)
		lambda(library[i]);

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n";

	return 0;
}
