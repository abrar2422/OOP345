/*
Name: Abrar Haque
Email: ahaque10@myseneca.ca
ID: 107465189
Date: July 11, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include "Car.h"
using namespace std;
namespace sdds {
	class Racecar :public Car {
		double m_booster = 0;
	public:
		//constructor
		Racecar(std::istream& in);
		//destructor
		~Racecar();
		//print
		void display(std::ostream& out)const;
		//getter
		double topSpeed()const;
	};
}
#endif // !SDDS_RACECAR_H
