#include <iostream>
#include "ConfirmationSender.h"

using namespace std;
namespace sdds {
    ConfirmationSender::ConfirmationSender() : _receipient{ nullptr }, _count{0} {}
    ConfirmationSender::~ConfirmationSender() {
        delete[] _receipient;
        _receipient = nullptr;
    }
    bool ConfirmationSender::search(const Reservation& res) {
        bool found = false;
        for (size_t i = 0; i < _count; i++) {
            found = (&res == _receipient[i]);
        }
        return found;
    }
    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
        Reservation temp = res;
        bool found = false;
        if (_count <= 0) {
            _count++;
            _receipient = new Reservation * [1];
            _receipient[0] = &temp;
        }
        else {
            for (size_t i = 0; i < _count; i++) {
                found = (&res == _receipient[i]);
            }
            if (!found) {
                Reservation* temp_arr[10];
                for (size_t i = 0; i < _count; i++) {
                    temp_arr[i] = _receipient[i];
                }
                _count++;
                delete[] _receipient;
                _receipient = nullptr;
                _receipient = new Reservation * [_count];
                for (size_t i = 0; i < _count - 1; i++) {
                    _receipient[i] = temp_arr[i];
                }
                _receipient[_count - 1] = &temp;
            }
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
        bool found = false;
        size_t i = 0;
        if (_receipient != nullptr) {
            while (i < _count && !found) {
                found = (&res == _receipient[i++]);
            }
            if (found) {
                _receipient[i - 1] = nullptr;
            }
        }
        return *this;
    }

    ostream& operator<<(ostream& os, ConfirmationSender& cs) {
        if (cs._count == 0) {
            os << "--------------------------\n";
            os << "Confirmations to Send\n";
            os << "--------------------------\n";
            os << "The object is empty!\n";
            os << "--------------------------\n";
        }
        else {
            os << "--------------------------\n";
            os << "Confirmations to Send\n";
            os << "--------------------------\n";
            for (size_t i = 0; i < cs.size(); i++) {
                if (cs._receipient[i] != nullptr) {
                    os << *cs._receipient[i];
                }
            }
            os << "--------------------------\n";
        }
        return os;
    }

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs) {
        if (cs._receipient != nullptr) {
            _receipient = new Reservation * [cs.size()];
            for (size_t i = 0; i < cs.size(); ++i) {
                _receipient[i] = cs._receipient[i];
            }
            _count = cs._count;
        }
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& cs) {
        if (cs._receipient != nullptr) {
            swap(_receipient, cs._receipient);
            _count = cs._count;
            cs._count = 0;
            cs._receipient = nullptr;
        }
    }
    size_t  ConfirmationSender::size() const { return _count; }
}