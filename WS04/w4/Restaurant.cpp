#include<iostream>
#include"Restaurant.h"
using namespace std;

namespace sdds {
	Restaurant::Restaurant() : _reserves{ nullptr }, _cnt{ 0 } {}
	Restaurant::~Restaurant() {
		delete[] _reserves;
		_reserves = nullptr;
		_cnt = 0;
	}
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
		_reserves = new Reservation[cnt];
		for (size_t i = 0; i < cnt; i++)
		{
			_reserves[i] = *reservations[i];
		}
		_cnt = cnt;
	}
	Restaurant::Restaurant(const Restaurant& src) { 
		_reserves = nullptr;
		*this = src; 
	}
	Restaurant& Restaurant::operator=(const Restaurant& src) {
		if (this != &src) {
			_cnt = src._cnt;
			delete[] _reserves;
			if (src._reserves != nullptr)
			{
				_reserves = new Reservation[_cnt];
				for (size_t i = 0; i < _cnt; i++) {
					_reserves[i] = src._reserves[i];
				}
			}
			else {
				_reserves = nullptr;
			}
		}
		return *this;
	}
	size_t Restaurant::size()const { return _cnt; }
	ostream& operator<<(ostream& os, const Restaurant& res) {
		static size_t CALL_CNT = 1;
		os << "--------------------------" << endl;
		os << "Fancy Restaurant" << "(" << CALL_CNT<< ")" << endl;
		os << "--------------------------" << endl;

		if (res.size() <= 0) {
			os << "This restaurant is empty!" << endl;
			os << "--------------------------" << endl;
		}
		else {
			for (size_t i = 0; i < res.size(); ++i) {
				os << res._reserves[i];
			}
			os << "--------------------------" << endl;
		}
		CALL_CNT++;
		return os;
	}
	Restaurant::Restaurant(Restaurant&& res) {
		if (res._reserves != nullptr)
		{
			swap(_reserves, res._reserves);
			_cnt = res._cnt;
			res._cnt = 0;
			res._reserves = nullptr;
		}
	}
	Restaurant& Restaurant::operator=(Restaurant&& res) {
		if (this != &res)
		{
			if (res._reserves != nullptr)
			{
				swap(_reserves, res._reserves);
				_cnt = res._cnt;
				res._cnt = 0;
				res._reserves = nullptr;
			}
		}
		return *this;
	}
}