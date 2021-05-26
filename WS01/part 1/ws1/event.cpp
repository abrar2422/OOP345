#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "event.h"
unsigned g_sysclock;
namespace sdds {
	static int counter =1;

	event::event() : m_description{0}, m_startTime{ 0 } {}
	bool event::isEmpty()const { return m_description[0] == 0; };
	void event::setEmpty() {
		m_startTime = 0;
		m_description[0] = 0;
	}
	void event::display() const{
		unsigned int hrs = m_startTime / 3600;
		unsigned int mins = (m_startTime % 3600)/60;
		unsigned int secs = m_startTime % 60;

		if(isEmpty()){
		/*	std::cout.width(3);*/
			std::cout.fill(' ');
			std::cout << counter << ". " << " | No Event |" << std::endl;
		}else{
			std::cout << counter << ". " <<
			std::cout.fill('0');
			std::cout.width(2);
			std::cout << hrs << ':';
			std::cout.fill('0');
			std::cout.width(2);
			std::cout << mins << ':';
			std::cout.fill('0');
			std::cout.width(2);
			std::cout << secs;
			std::cout << " -> ";
			std::cout << m_description << std::endl;
		/*	std::cout << counter << hrs << ":" << mins << ":" << secs << "=>" << m_description;*/
		}
		counter++;
	}
	void event::set(char* addr) {
		if (addr != nullptr && addr[0] != 0) {
			strcpy(m_description, addr);
			m_startTime = g_sysclock;
		}
		else {
			event::setEmpty();
		}
	}

}