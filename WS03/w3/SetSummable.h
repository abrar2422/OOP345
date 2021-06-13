/*
Name: Abrar Haque
Email: ahaque10@myseneca.ca
ID: 107465189
Date: June 13, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef _SET_SUMMABLE_H
#define _SET_SUMMABLE_H
#include <iostream>
#include "Set.h"
namespace sdds {
	template <size_t N, typename T>
	class SetSummable :public Set<N,T> {
	public:
		T accumulate(const std::string& filter)const {
	
			T accumulator(filter);
			for (size_t i = 0; i < this->size(); i++)
			{
				bool isCompatible = this->get(i).iscompatiblewith(accumulator);
				if (isCompatible)
				{
					accumulator += this->get(i);
				}
			}

			return accumulator;
		}
	};
}
#endif // !_SDDS_SETSUMMABLA_H

