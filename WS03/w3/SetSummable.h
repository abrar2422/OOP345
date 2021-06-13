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

