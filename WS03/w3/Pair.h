/*
Name: Abrar Haque
Email: ahaque10@myseneca.ca
ID: 107465189
Date: June 10, 2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef _SDDS_PAIR_H
#define _SDDS_PAIR_H
#include <iostream>
namespace sdds {
	template<typename V, typename K>
	class Pair {
	public:
		K m_key;
		V m_value;
	public:
		Pair() {}
		Pair(const K& key, const V& value) {
			m_key = key;
			m_value = value;
		}
		const V& value() const { return m_value; }
		const K& key()const { return m_key; }
		virtual void display(std::ostream& os)const {
			os << m_key << " : " << m_value << std::endl;
		}
	};
	template<typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(std::cout);
		return os;
	}
}
#endif // !_SDDS_PAIR_H
