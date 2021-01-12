/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date Started: November/9th/2020
Date of completion: November/12th/2020
Date Due: November/15th/2020
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
		auto trim = [](std::string remove)
		{
			// if not empty and no space at begginning and end then do the following 
			if ((!remove.empty() && !all_of(remove.begin(), remove.end(), isspace)))
			{
				// check first index for space, if it is then trim it  
				while (remove.at(0) == ' ')
					remove = remove.substr(1, remove.length() - 1);

				// check last index for space, if it is then trim it 
				while (remove.at(remove.length() - 1) == ' ')
					remove = remove.substr(0, remove.length() - 1);
			}
			return remove;
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
					t_obj.m_price = stod(trim(song_str.substr(85, 5)));
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
			out << s_music << std::endl; 
		};

		// lambda function that works with the time 
		auto time = [](int sum, const Song& songs)
		{
			// combined total of song length
			sum += songs.s_length; 
			return sum;
		};

		// total song time
		int total = std::accumulate(s_collect.begin(), s_collect.end(), 0, time);
		
		// vector (iterator)
		for_each(s_collect.begin(), s_collect.end(), show);
		
		// all the time conversions 
			// hours 
		int hrs = total / 3600; 

			// minutes 
		total = total % 3600;
		int mins = total / 60;

			// seconds 
		total = total % 60;
		int secs = total;

		// ouput which is specified
		out << "----------------------------------------------------------------------------------------\n";
		out << "|                                                        " << "Total Listening Time: " << hrs << ":" << mins << ":" << secs << " |" << std::endl;
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
			// removed endl here
		out << " | " << theSong.m_price << " |"; 
		return out;
	}

	// recieve name of field as param
	void SongCollection::sort(std::string s)
	{
		// if title then do following 
		if (s == "title")
		{
			std::sort(s_collect.begin(), s_collect.end(), [](const Song& first, const Song& second) 
			{
					// title of song compared and returned 
				return first.s_title < second.s_title; 
			});
		}

		// if album then do following 
		else if (s == "album")
		{
			std::sort(s_collect.begin(), s_collect.end(), [](const Song& first, const Song& second) 
			{
					// album of song compared and returned 
				return first.s_album < second.s_album; 
			});
		}

		// else its length and do the following 
		else
		{
			std::sort(s_collect.begin(), s_collect.end(), [](const Song& first, const Song& second) 
			{
					// length of song compared and returned 
				return first.s_length < second.s_length;
			});
		}
	}

	// remove [None] 
	void SongCollection::cleanAlbum()
	{
		// lamba for cleaning the album 
		auto clean = [](Song& album_clean)
		{
			// if album has "[None]" then remove it 
			if (album_clean.s_album == "[None]")
			{
				album_clean.s_album.clear();
			}
		};

		// vector (iterator)
		std::for_each(s_collect.begin(), s_collect.end(), clean);
	}

	// recieve name of artist as param and do more
	bool SongCollection::inCollection(std::string n_artist) const
	{
		// setting local obj to 0 
		int s = 0; 

		// lamdba for returning artist that matches param
		auto check = [&](const Song& collection)
		{
			// if artist is same as artist of song then do following 
			if (n_artist == collection.s_artist)
			{
				s++;
			}
		};

		// vector (iterator) 
		std::for_each(s_collect.begin(), s_collect.end(), check);

		return s;
	}

	// recieve name of artist as param and do more
	std::list<Song> SongCollection::getSongsForArtist(std::string n_artist) const
	{
		// recieve all songs 
		std::list<Song> collection_song(s_collect.size());

		// lamba for cheking the name of artists 
		auto compare = [&](const Song& artist_name)
		{
			return (artist_name.s_artist == n_artist);
		};

		// copy songs 
		auto songs = std::copy_if(s_collect.begin(), s_collect.end(), collection_song.begin(), compare);

		// cut the names of the artist that aren't wanted/desired 
		collection_song.resize(std::distance(collection_song.begin(), songs));

		return collection_song;
	}
}