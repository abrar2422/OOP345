/*
Name: Abrar Haque
Email: ahaque10@myseneca.ca
ID: 107465189
Date: July 11, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef _SDDS_AUTOSHOP_H
#define _SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"
namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		//operator overloads
		Autoshop& operator+=(Vehicle* theVehicle);
		//destructor
		~Autoshop();
		//print
		void display(std::ostream& out) const;
		//template
		template <class T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++) {
				if (test(*ptr)) {
					vehicles.push_back(*ptr);
				}
			}

		}

	};

}

#endif // !_SDDS_AUTOSHOP_H
