#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Movie.h"

namespace sdds {
	size_t Movie::numMovies = 0;

	Movie::Movie() { numMovies++; }
	Movie::~Movie() { 
		delete[] _name;
		_name = nullptr;
		numMovies--; 
	}
	Movie::Movie(const char* name, Genre gen) {
		allocateAndCopy(name);
	}
	Movie::Movie(const Movie& src) {
		_name = nullptr;
		*this = src;
	}
	Movie& Movie::operator=(const Movie& src){
		if (this != &src) {
			_genre = src._genre;
			allocateAndCopy(src._name);
		}
		else
		{
			_name = nullptr;
		}
		return *this;
	}

	Movie::Movie(Movie&& src) {*this = std::move(src);}
	Movie& Movie::operator=(Movie&& src) {
		if (this != &src)
		{
			delete[] _name;
			_name = src._name;
			_genre = src._genre;
			src._name = nullptr;
		}
		return *this;
	}
	std::string Movie::review(std::string rev) {
		std::string normReview = "";
		std::string bar = "|";
		if (_name && !rev.empty()) {
			normReview = _name + bar + rev;
		}
		else {
			normReview = "be the first to review";
		}
		return normReview;
	}
	size_t Movie::noOfMovies() { return numMovies; }
	void Movie::allocateAndCopy(const char* str) {
		if (str) {
			delete[] _name;
			_name = new char[strlen(str) + 1];
			strcpy(_name, str);
		}
	}
}