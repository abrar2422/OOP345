#ifndef _SDDS_PAIRSUMMABLE_H
#define _SDDS_PAIRSUMMABLE_H
#include "Pair.h"
namespace sdds {
	template<typename V, typename K>
	class PairSummable : Pair<V,K>{
		static V m_initial_value;
		static size_t m_width;
	public:
		PairSummable() {}
		static const V& get_initial_value() { return m_initial_value; }
		PairSummable(const K& key, const V& value = initial): Pair<V,K>(key,value){
			K.size() != 0 && m_width = K.size();
		}
		bool iscompatiblewith(const PairSummable<V,K>& b)const{
			return this->key() == b.key();
		}
		PairSummable<V,K>& operator+=(const PairSummable<V, K>& b) {
			PairSummable<V, K> temp(b.value() + this->value() , b.key());
			return temp;
		}
		virtual void display(std::ostream& os)const {
			os.width(m_width);
			os.setf(ios::left);
			Pair<V,K>::Display(os);
			os.unsetf(std::ios::left);
		}
	};

	
	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& b) {
		PairSummable<std::string,std::string> temp(b.value() + ", " + this->value(), b.key());
		return temp;
	}
	template<> std::string PairSummable<std::string, std::string>::m_initial_value = 0;
	template<typename V, typename K>
	size_t PairSummable<V, K>::m_width = 0u;
}
#endif // !_SDDS_PAIRSUMMABLE_H
