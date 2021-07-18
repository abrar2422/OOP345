#include <fstream>
#include <sstream>
#include <iomanip>
#include "SongCollection.h"
using namespace std;
namespace sdds {
	SongCollection::SongCollection(string fileName) {
		fstream file(fileName);
		if (!file) {
			std::cerr << "ERROR: Cannot open file [ " << fileName << " ].\n";
		}
		file.clear();
		file.seekg(std::ios::beg);
		do
		{
			string st, title, artist, album, year, lengthInSecs, price;
			int duration{ 0 }, mins{ 0 }, secs{0};
			Song sg;
			getline(file, st, '\n');
			trim(st);

			sg._title = trim(extract(st, 25));
			sg._artist = trim(extract(st, 25));
			sg._album = trim(extract(st, 25));
			sg._release_year = trim(extract(st, 5));
			lengthInSecs = trim(extract(st, 5));
			sg._price = trim(extract(st, 5));

			stringstream ss(lengthInSecs); //convert to stringstream
			ss >> duration; //string to number
			mins = duration / 60; //4
			secs = duration % 60; //5
			stringstream length_breakdown;
			length_breakdown << mins << ':' << setw(2) << setfill('0') << secs;
			length_breakdown >> sg._length;


			songs.push_back(sg);

		} while (file);
		songs.pop_back();
	}
	void SongCollection::display(std::ostream& os) const {
		for (auto i = songs.begin(); i != songs.end(); i++) {
			os << *i;
		}
	}
	std::ostream& operator<<(std::ostream& os, const Song& tSong) {
		os << "| ";
		os << left << setw(20) << tSong._title << " | ";
		os << left << setw(15) << tSong._artist << " | ";
		os << left << setw(20) << tSong._album << " | ";
		os << right << setw(6) << tSong._release_year << " | ";
		os << tSong._length << " |";
		os << tSong._price << " |" << endl;
		return os;
	}
	string extract(string& str, int size) {
		string str_extract;
		str_extract = str.substr(0, size);
		str.erase(0, size);
		return str_extract;
	}
	string trim(string str) {
		str.erase(str.find_last_not_of(' ') + 1);
		str.erase(0, str.find_first_not_of(' '));
		return str;
	}
}