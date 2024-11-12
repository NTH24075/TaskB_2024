#ifndef INFOR_USER_H
#define INFOR_USER_H

#include <string>
#include <iostream>

class infor_user {
private:
    string name;
    string number_phone;
public:
    infor_user(string fullname = "", string number = "");
    string getName() const;
    string getNumber_phone() const;
    friend ostream& operator<<(ostream& os, const infor_user& user);
};

#endif