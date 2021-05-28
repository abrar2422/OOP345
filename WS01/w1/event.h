#ifndef _SDDS_Event_H
#define _SDDS_Event_H
namespace sdds {
	class Event {
		char* m_description{nullptr};
		unsigned int m_startTime{0};
	public:
		Event();
		~Event();
		Event(const Event& src);
		Event& operator=(const Event& src);
		void display()const;
		void set(const char* desc=nullptr);
		void setEmpty();
		bool isEmpty()const;
	};
}
#endif // !_SDDS_Event_H
