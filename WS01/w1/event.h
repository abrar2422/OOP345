/*
Name: Abrar Haque
Email: ahaque10@myseneca.ca
Student ID: 107465189
Date: May 30, 2021
I have done all the coding myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef _SDDS_Event_H
#define _SDDS_Event_H
extern unsigned int g_sysClock;
namespace sdds {
	class Event {
		char* m_description{nullptr};
		unsigned int m_startTime{0};
		void setEmpty();
		bool isEmpty()const;
	public:
		Event();
		~Event();
		Event(const Event& src);
		Event& operator=(const Event& src);
		void display()const;
		void set(const char* desc=nullptr);
		
		
	};
}
#endif // !_SDDS_Event_H
