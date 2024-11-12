#include "infor_user.h"

infor_user::infor_user(string fullname, string number) {
    this->name = fullname;
    this->number_phone = number;
}

string infor_user::getName() const {
    return this->name;
}

string infor_user::getNumber_phone() const {
    return this->number_phone;
}

ostream& operator<<(ostream& os, const infor_user& user) {
    os << "Name: " << user.getName() << ", Phone: " << user.getNumber_phone();
    return os;
}