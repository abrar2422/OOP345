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

		cout << _res_id << " " << _name_on_reservation << " " << _email << " " << _num_of_people << " " << _res_day << " " << _res_hour << endl;
	}
	//friend helpers
	ostream& operator<<(ostream& os, const Reservation& res){
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
