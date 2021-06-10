#ifndef _SDDS_TIMEDEVENTS_H
#define _SDDS_TIMEDEVENTS_H
#include <iostream>
#include <chrono>

namespace sdds {
	const int MAX_EVENTS = 10;
	class TimedEvents {
		int m_currentStoredRecord;
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;
		struct {
			std::string m_name;
			std::string m_unitTime;
			std::chrono::steady_clock::duration m_duration;
		}Event[MAX_EVENTS];

	public:
		TimedEvents() {
			m_currentStoredRecord = 0;
		}
		void startClock() {
			m_startTime = std::chrono::steady_clock::now();
		}
		void stopClock() {
			m_endTime = std::chrono::steady_clock::now();
		}
		void addEvent(const char* name) {
			Event[m_currentStoredRecord].m_name = name;
			Event[m_currentStoredRecord].m_duration = std::chrono::duration_cast<std::chrono::milliseconds>(m_endTime - m_startTime);
			Event[m_currentStoredRecord].m_unitTime = "Nanoseconds";
			
			m_currentStoredRecord++;
		}

		friend std::ostream& operator<<(std::ostream& os, TimedEvents& te) {
			os << "execution times" << std::endl;
			
			for (int i = 0) {
			}
		}
	};
}
#endif // !_SDDS_TIMEDEVENTS_H
