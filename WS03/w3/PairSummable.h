#ifndef _SDDS_PAIRSUMMABLE_H
#define _SDDS_PAIRSUMMABLE_H
#include "Pair.h"
namespace sdds {
	template<typename V, typename K>
	class PairSummable : pair<V,K>{
		V m_initial_value;
		size_t m_width = 0;
	public:
		PairSummable() {}
		PairSummable(const K& key, const V& value = initial) {
			Pair<int, std::string>(key, value);
			k.size() != 0 && m_width = k.size();
		}
		bool iscompatiblewith(const PairSummable<V,K>& b)const{
			return m_key == b.m_key;
		}
		PairSummable<V,K>& operator+=(cosnt PairSummable<V, K>& b) {
			m_initial_value = b.m_initial_value;
		}
		virtual void display(std::ostream& os)const {
			os.width(m_width);
			os.setf(ios::left);
			display(os);
		}
	};
}
#endif // !_SDDS_PAIRSUMMABLE_H
