#ifndef _SDDS_PAIRSUMMABLE_H
#define _SDDS_PAIRSUMMABLE_H
#include "Pair.h"
namespace sdds {
	template<typename V, typename K>
	class PairSummable :public Pair<V,K>{
	public:
		static V m_initial_value;
		static size_t m_width;
	public:
		PairSummable() {}
		static const V& get_initial_value() { return m_initial_value; }
		PairSummable(const K& key, const V& value = m_initial_value): Pair<V,K>(key,value){
			(key.size() > m_width) && (m_width = key.size());
		}
		bool iscompatiblewith(const PairSummable<V,K>& b)const{
			return this->key() == b.key();
		}
		PairSummable<V,K>& operator+=(const PairSummable<V, K>& b) {
			this->m_value = this->value() + b.value();
			return *this;
		}
		virtual void display(std::ostream& os)const {
			os.width(m_width);
			os.setf(std::ios::left);
			Pair<V,K>::display(os);
			os.unsetf(std::ios::left);
		}
	};

	//operator+= specializtion for strings
	template<>
 	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& b) {
		if (m_value.empty()){
			this->m_value = b.m_value;
		}else
		{
			this->m_value = m_value + ", " + b.m_value;
		}

		return *this;
	}
	
	
	//class variable initialization
	template<> int PairSummable<int, std::string>::m_initial_value = 0;
	template<> std::string PairSummable<std::string, std::string>::m_initial_value = "";
	template<typename V, typename K>
	size_t PairSummable<V, K>::m_width = 0u;
}
#endif // !_SDDS_PAIRSUMMABLE_H
