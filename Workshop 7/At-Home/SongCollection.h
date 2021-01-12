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

// File Headers 
#ifndef _SDDS_SONGCOLLECTION_H
#define _SDDS_SONGCOLLECTION_H
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <istream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>
#include <numeric>

// sdds namespace 
namespace sdds
{
	// song struct 
		// includes info about song
	struct Song
	{
		std::string s_artist;
		std::string s_title;
		std::string s_album;
		double m_price; // had to change to m_price because prof file has specified that 
		std::string s_release;
		int s_length;
	};

	// SongCollection class
	class SongCollection
	{
		// song collection 
		std::vector<Song> s_collect;

		// public 
	public:

		// custom constructor 
		SongCollection(const char* song);

		// print into paramater  
			// updated for at-home
		void display(std::ostream& out) const;

		// recieve name of field as param
		void sort(std::string s);

		// remove [None] 
		void cleanAlbum();

		// recieve name of artist as param and do more
		bool inCollection(std::string n_artist) const;

		// recieve name of artist as param and do more
		std::list<Song> getSongsForArtist(std::string n_artist) const;
	};

	// free helper function 
		// displays output in specified format
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !_SDDS_SONGCOLLECTION_H