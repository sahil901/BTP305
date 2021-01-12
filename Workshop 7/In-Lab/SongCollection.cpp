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
#include "SongCollection.h"

// sdds namespace 
namespace sdds
{
	// custom constructor 
	SongCollection::SongCollection(const char* song)
	{
		// lambda for trim
		auto trim = [](std::string s)
		{
			// if not empty and no space at begginning and end then do the following 
			if ((!s.empty() && !all_of(s.begin(), s.end(), isspace)))
			{
				// check first index for space, if it is then trim it  
				while (s.at(0) == ' ')
					s = s.substr(1, s.length() - 1); 

				// check last index for space, if it is then trim it 
				while (s.at(s.length() - 1) == ' ')
					s = s.substr(0, s.length() - 1); 
			}
			return s;
		};

		// local string 
		std::string song_str = "";

		// creating a instance of the file 
		std::fstream s_song_txt;

		// opening the file 
		s_song_txt.open(song);

		// if file incorrect then throw exception
		if (!s_song_txt)
			throw "File Cannot Be Opened!";

		// do following otherwise 
		else
			while (std::getline(s_song_txt, song_str))
			{
				// if full do following
				if (!song_str.empty())
				{
					// temp obj
					Song t_obj;

					// length of the song set to 0 
					int s_length = 0;

					// trimming 
						// title of song 
					t_obj.s_title = trim(song_str.substr(0, 24));
						// artist of song 
					t_obj.s_artist = trim(song_str.substr(24, 25));
						// album of song
					t_obj.s_album = trim(song_str.substr(50, 25));
						// song release 
					t_obj.s_release = trim(song_str.substr(75, 5));
						// length of song 
					s_length = stoi(trim(song_str.substr(80, 5)));
					t_obj.s_length = s_length;
						// price of song
							// also adding to vector 
					t_obj.s_price = stod(trim(song_str.substr(85, 5)));
					s_collect.push_back(t_obj);
				}
			}
	}

	// print into parameter 
	void SongCollection::display(std::ostream& out) const
	{
		// lambda function that displays the songs 
		auto show = [&](const Song& s_music)
		{
			out << s_music;
		};

		for_each(s_collect.begin(), s_collect.end(), show);
	}

	// free helper function 
		// displays output in specified format
	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		// time conversions 
			// minutes
		size_t song_min = theSong.s_length / 60;

			// seconds 
		size_t song_sec = theSong.s_length % 60;

		// printing out the info in specified format 
		out << "| " << std::setw(20) << std::left << theSong.s_title << " | " << std::setw(15) << std::left << theSong.s_artist << " | " << std::setw(20) << std::left << theSong.s_album << " | " << std::setw(6) << std::right << theSong.s_release << " | " << song_min << ":";

		// seconds (for the duration of the song)
		if (song_sec < 10)
			out << "0" << song_sec;
		else
			out << song_sec;

		// price 
		out << " | " << theSong.s_price << " |" << std::endl;
		return out;
	}
}