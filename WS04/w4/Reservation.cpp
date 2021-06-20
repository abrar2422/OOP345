#include<iostream>
#include<string>
#include<iomanip>
#include "Reservation.h"
using namespace std;

namespace sdds {
	//constructors
	Reservation::Reservation() : _res_id{ "" }, _name_on_reservation{ "" }, _email{ "" }, _num_of_people{ 0 }, _res_day{ 0 }, _res_hour{ 0 } {}
	Reservation::Reservation(const std::string& res){
		string str_modifiable = res;

		_res_id = trim(extract(str_modifiable, ":"));
		str_modifiable.erase(0, str_modifiable.find(':') + 1);
		_name_on_reservation = trim(extract(str_modifiable, ","));
		str_modifiable.erase(0, str_modifiable.find(',') + 1);
		_email = "<" + trim(extract(str_modifiable, ",")) + ">";
		str_modifiable.erase(0, str_modifiable.find(',') + 1);
		_num_of_people = stoi(trim(extract(str_modifiable, ",")));
		str_modifiable.erase(0, str_modifiable.find(',') + 1);
		_res_day = stoi(trim(extract(str_modifiable, ",")));
		str_modifiable.erase(0, str_modifiable.find(',') + 1);
		_res_hour = stoi(trim(extract(str_modifiable, ",")));
	}
	//friend helpers
	ostream& operator<<(ostream& os, const Reservation& res){
		size_t hr = res._res_hour;
		string serv_type[4]{ "Breakfast", "Lunch", "Dinner", "Drinks" };
		int val{ 0 };
		if (hr >=6 && hr <=9){
			val = 0;
		}
		else if (hr >= 11 && hr <= 15) {
			val = 1;
		}
		else if (hr >= 17 && hr <= 21) {
			val = 2;
		}
		else{
			val = 3;
		}
		os << "Reservation ";
		os << setw(10) << setfill(' ') << right << res._res_id << ": ";
		os << setw(20) << setfill(' ') << right << res._name_on_reservation << "  ";
		os << setw(24) << setfill(' ') << left << res._email;
		os << serv_type[val] << " on day " << res._res_day << " @ " << res._res_hour << ":00" << " for " << res._num_of_people;
		if (res._num_of_people > 1)
		{
			os << " people." << '\n';
		}
		else {
			os << " person." << '\n';
		}
		return os;
	}
	//helpers
	string extract(string str, string delimeter){
		string str_extract;
		str_extract = str.substr(0, str.find(delimeter));
		return str_extract;
	}
	string trim(string str){
		str.erase(str.find_last_not_of(' ') + 1);
		str.erase(0, str.find_first_not_of(' '));
		return str;
	}
}
