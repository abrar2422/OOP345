#ifndef _SDDS_MOVIE_H
#define _SDDS_MOVIE_H
#include <iostream>
namespace sdds {
	enum class Genre {
		Crime, Comedy, Drama, None
	};
	class Movie {
		static size_t numMovies;
		char* _name = nullptr;
		Genre _genre = Genre::None;
	public:
		//constructors
		Movie();
		~Movie();
		Movie(const char* name, Genre gen=Genre::Comedy);
		//copy constructor
		Movie(const Movie& src);
		Movie& operator=(const Movie& src);
		//move constructor
		Movie(Movie&& src);
		Movie& operator=(Movie&& src);
		//Query
		std::string review(std::string review);
		//helpers
		void allocateAndCopy(const char* str);
		//class functions
		static size_t noOfMovies();

	};

}
#endif // !_SDDS_HEADER
