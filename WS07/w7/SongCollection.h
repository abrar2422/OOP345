#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <string>
#include <vector>
namespace sdds {
	struct Song {
		std::string _artist = "";
		std::string _title = "";
		std::string _album = "";
		std::string _price = "";
		std::string _release_year = "";
		std::string _length = "";
	};
	class SongCollection {
		std::vector<Song> songs;
	public:
		SongCollection(std::string);
		void display(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const Song& tSong);
	std::string extract(std::string& str, int size);
	std::string trim(std::string str);
}
#endif // !SDDS_SONGCOLLECTION_H
