#ifndef _SDDS_SET_H
#define _SDDS_SET_H

namespace sdds {
	template <size_t N, typename T >
	class Set {
		size_t m_tracker = 0;
		T m_collection[N];
	public:
		size_t size() const{return m_tracker;}
		const T& get(size_t idx)const{
			return m_collection[idx];
		}
		void operator+=(const T& item) {
			if (m_tracker < N) {
				m_collection[m_tracker] = item;
				m_tracker++;
			}
		}
	};
}


#endif // !_SDDS_SET_H
