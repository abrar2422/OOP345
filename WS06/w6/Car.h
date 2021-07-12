/*
Name: Abrar Haque
Email: ahaque10@myseneca.ca
ID: 107465189
Date: July 11, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef _SDDS_CAR_H
#define _SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"
namespace sdds {
	class Car : public Vehicle {
		std::string _maker = "";
		std::string _condition= "";
		double _topSpeed = 0;
	public:
		//constructor
		Car(std::istream& in);
		//destructor
		~Car();
		//getters
		std::string condition() const;
		double topSpeed() const;
		//print
		void display(std::ostream& out) const;
	};
	//helpers
	std::string extract(std::string str, std::string delimeter);
	std::string trim(std::string str);
}
#endif // !_SDDS_CAR_H
