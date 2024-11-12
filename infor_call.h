#ifndef INFOR_CALL_H
#define INFOR_CALL_H

#include <string>
#include <iostream>
#include <sstream>

class infor_call {
private:
    string number_phone;
    int minute;
    string time_start;
    string day;
    string region;
    int day_of_week;
public:
    infor_call(string number = "", int minute = 0, string start = "", string day = "", string region = "");
    string getNumber_phone() const;
    int getMinute() const;
    string getTime_start() const;
    string getDay() const;
    string getRegion() const;
    int getDayofWeek() const;
    int setDayofWeek(string date);
    friend ostream& operator<<(ostream& os, const infor_call& a);
};

int sstoi(string s);

#endif