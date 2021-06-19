#ifndef _SDDS_RESERVATION_H
#define _SDDS_RESERVATION_H
namespace sdds {
	class Reservation {
		std::string _res_id;
		std::string _name_on_reservation;
		std::string _email;
		size_t _num_of_people;
		size_t _res_day;
		size_t _res_hour;
	public:
		Reservation();
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
	};

	std::string extract(std::string str, std::string delimeter);
	std::string trim(std::string str);
}

#endif // !_SDDS_RESERVATION_H
