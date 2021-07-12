#ifndef _SDDS_RESTAURANT_H
#define _SDDS_RESTAURANT_H
#include <iostream>
#include "Reservation.h"
namespace sdds {
    class Restaurant {
        Reservation* _reserves;
        size_t _cnt;
    public:
        //default constructors
        Restaurant();
        ~Restaurant();
        Restaurant(const Reservation* reservations[], size_t cnt);
        //copy constructor and assign
        Restaurant(const Restaurant&);
        Restaurant& operator=(const Restaurant&);
        //move constructor and assign
        Restaurant(Restaurant&& res);
        Restaurant& operator=(Restaurant&&);
        //friends
        friend std::ostream& operator<<(std::ostream&, const Restaurant&);
        //getters
        size_t size()const;
    };
}
#endif // !_SDDS_RESTAURANT_H
