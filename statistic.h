#ifndef STATISTIC_H
#define STATISTIC_H

#include <string>

class statistic {
private:
    string name;
    string number_phone;
    int call_fee;
    int number_NH;
    int number_LC;
    int number_X;
    int number_RX;
public:
    statistic(string name = "", string number_phone = "", int call_fee = 0, int number_NH = 0, int number_LC = 0, int number_X = 0, int number_RX = 0);
    string getName();
    string getNumber_phone();
    int getCall_fee();
    int getNumber_NH();
    int getNumber_LC();
    int getNumber_X();
    int getNumber_RX();
};

#endif