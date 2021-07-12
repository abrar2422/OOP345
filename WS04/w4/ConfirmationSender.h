#ifndef _SDDS_CONFIRMATIONSENDER_H
#define _SDDS_CONFIRMATIONSENDER_H
#include <iostream>
#include "Reservation.h"
namespace sdds {
    class ConfirmationSender {
        Reservation** _receipient;
        size_t _count;

    public:
        //default constructors
        ConfirmationSender();
        ~ConfirmationSender();
        //copy constructor and assign
        ConfirmationSender(const ConfirmationSender&);
        ConfirmationSender& operator=(const ConfirmationSender&) { return *this; }
        //move constructor and assign
        ConfirmationSender(ConfirmationSender&&);
        ConfirmationSender& operator=(ConfirmationSender&&) { return *this; }
        //overloads
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        //friends
        friend std::ostream& operator<<(std::ostream&, ConfirmationSender&);
        //getters
        size_t size() const;
        //public members
        bool search(const Reservation&);
    };
}
#endif // !_SDDS_CONFIRMATIONSENDER_H
