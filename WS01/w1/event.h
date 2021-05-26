#ifndef _SDDS_EVENT_H
#define _SDDS_EVENT_H
namespace sdds {
	class event {
		char* m_description{nullptr};
		unsigned int m_startTime{0};
	public:
		event();
		~event();
		void display()const;
		void set(const char* desc=nullptr);
		void setEmpty();
		bool isEmpty()const;
	};
}
#endif // !_SDDS_EVENT_H
