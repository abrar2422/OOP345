#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
namespace sdds {
	struct Song {
		std::string _artist = "";
		std::string _title = "";
		std::string _album = "";
		std::string _price = "";
		std::string _release_year = "";
		std::string _length = "";
		int len = 0;
		double m_price =0;

	};
	class SongCollection {
		int totalPlayTime = 0;
		std::vector<Song> songs;
	public:
		SongCollection(std::string);
		void sort(std::string sorter);
		void cleanAlbum();
		bool inCollection(std::string name) const;
		std::list<Song> getSongsForArtist(std::string name)const;
		void display(std::ostream& os);
	};
	std::ostream& operator<<(std::ostream& os, const Song& tSong);
	std::string extract(std::string& str, int size);
	std::string trim(std::string str);
}
#endif // !SDDS_SONGCOLLECTION_H
