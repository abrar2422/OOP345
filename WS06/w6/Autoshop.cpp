/*
Name: Abrar Haque
Email: ahaque10@myseneca.ca
ID: 107465189
Date: July 11, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <vector>
#include "Autoshop.h"
using namespace std;
namespace sdds {
	//operator overload
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle){
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	//destructor
	Autoshop::~Autoshop() {
		for (auto ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++)
			delete* ptr;
	}
	//print
	void Autoshop::display(std::ostream& out) const{
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;
		for (auto ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++) {
			(*ptr)->display(out);
			out << endl;
		}

		out << "--------------------------------" << endl;

	}
}