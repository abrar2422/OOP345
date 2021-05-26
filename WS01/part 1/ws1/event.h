#ifndef _SDDS_EVENT_H
#define _SDDS_EVENT_H
namespace sdds {
	class event {
		char m_description[128];
		unsigned int m_startTime;
	public:
		event();
		void display()const;
		void set(char* addr=nullptr);
		void setEmpty();
		bool isEmpty()const;
	};
}
#endif // !_SDDS_EVENT_H
