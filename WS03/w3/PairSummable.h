#ifndef _SDDS_PAIRSUMMABLE_H
#define _SDDS_PAIRSUMMABLE_H
#include "Pair.h"
namespace sdds {
	template<typename V, typename K>
	class PairSummable : Pair<V,K>{
		V m_initial_value;
		size_t m_width = 0;
	public:
		PairSummable() {}
		PairSummable(const k& key, const v& value = initial) {

		}
		bool isCompatibleWith(const PairSummable<V,K>& b)const{}
	};
}
#endif // !_SDDS_PAIRSUMMABLE_H
