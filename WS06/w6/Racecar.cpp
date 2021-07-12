/*
Name: Abrar Haque
Email: ahaque10@myseneca.ca
ID: 107465189
Date: July 11, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <string>
#include <sstream>
#include "Racecar.h"

using namespace std;

namespace sdds {
	//constructor
	Racecar::Racecar(istream& in):Car(in) {
		string ss;
		getline(in, ss);
		string booster = ss.substr(ss.find_last_of(",") +1); //extract booster end of string
		stringstream str(booster);
		str >> m_booster; // string to double through stringstream
	}
	//destructor
	Racecar::~Racecar(){}
	//print
	void Racecar::display(ostream& out)const {
		Car::display(out);
		out << "*";
	}
	//getter
	double Racecar::topSpeed()const { return Car::topSpeed() * (1 + m_booster); }
}