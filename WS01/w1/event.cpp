#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "event.h"
unsigned g_sysclock;
namespace sdds {
	static int counter =1;

	event::event() {}
	event::~event() { 
		delete[] m_description; 
		m_description = nullptr;
	}
	event::event(const event& src) {
		/**this = src;*/
		m_startTime = src.m_startTime;
		if (src.m_description != nullptr) {
			delete[] m_description;
			m_description = new char[strlen(src.m_description) +1];
			strcpy(m_description, src.m_description);
		}
		else {
			setEmpty();
		}
		
	}
	event& event::operator=(const event& src) {
		if (this != &src){
			m_startTime = src.m_startTime;
			delete[] m_description;
			if (src.m_description != nullptr) {
				delete[] m_description;
				m_description = new char[strlen(src.m_description) + 1];
				strcpy(m_description, src.m_description);
			}
			else {
				setEmpty();
			}
		}
		return *this;
	}
	bool event::isEmpty()const { return m_description == nullptr; };
	void event::setEmpty() {
		m_startTime = 0;
		m_description = nullptr;
	}
	void event::display() const{
		unsigned int hrs = m_startTime / 3600;
		unsigned int mins = (m_startTime % 3600)/60;
		unsigned int secs = m_startTime % 60;
		
		std::cout.fill(' ');
		std::cout.width(2);
		std::cout << counter << ". ";
		if(isEmpty()){
			std::cout  << "| No Event |" << std::endl;
		}else{
			std::cout.fill('0');
			std::cout.width(2);
			std::cout << hrs << ':';
			std::cout.fill('0');
			std::cout.width(2);
			std::cout << mins << ':';
			std::cout.fill('0');
			std::cout.width(2);
			std::cout << secs;
			std::cout << " => ";
			std::cout << m_description << std::endl;
		}
		counter++;
	}
	void event::set(const char* desc) {
		if (desc != nullptr && desc[0] != 0) {
			int size = strlen(desc);
			m_description = new char[size +1];
			strcpy(m_description, desc);
			m_startTime = g_sysclock;
		}
		else {
			event::setEmpty();
		}
	}

}