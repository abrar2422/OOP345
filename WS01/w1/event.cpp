/*
Name: Abrar Haque
Email: ahaque10@myseneca.ca
Student ID: 107465189
Date: May 30, 2021
I have done all the coding myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "event.h"
unsigned int g_sysClock = 0;
namespace sdds {
	Event::Event() {}
	Event::~Event() { 
		delete[] m_description; 
		m_description = nullptr;
	}
	Event::Event(const Event& src) {
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
	Event& Event::operator=(const Event& src) {
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
	bool Event::isEmpty()const { return m_description == nullptr; };
	void Event::setEmpty() {
		m_startTime = 0;
		m_description = nullptr;
	}
	void Event::display() const{
		static int counter = 1;
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
	void Event::set(const char* desc) {
		if (desc != nullptr && desc[0] != 0) {
			int size = strlen(desc);
			m_description = new char[size +1];
			strcpy(m_description, desc);
			m_startTime = g_sysClock;
		}
		else {
			Event::setEmpty();
		}
	}

}