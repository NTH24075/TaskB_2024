#include "infor_call.h"

infor_call::infor_call(string number, int minute, string start, string day, string region) {
    this->number_phone = number;
    this->minute = minute;
    this->time_start = start;
    this->day = day;
    this->region = region;
    this->day_of_week = setDayofWeek(day);
}

string infor_call::getNumber_phone() const {
    return this->number_phone;
}

int infor_call::getMinute() const {
    return this->minute;
}

string infor_call::getTime_start() const {
    return this->time_start;
}

string infor_call::getDay() const {
    return this->day;
}

string infor_call::getRegion() const {
    return this->region;
}

int infor_call::getDayofWeek() const {
    return this->day_of_week;
}

int sstoi(string s) {
    int num = 0;
    for(int i = 0; i < s.size(); i++) {
        if(isdigit(s[i]))
            num = num*10 + (s[i]-'0');
    }
    return num;
}

int infor_call::setDayofWeek(string date) {
    stringstream ss(date);
    string _day, _month, _year;
    getline(ss, _day, '/');
    getline(ss, _month, '/');
    getline(ss, _year, '/');
    int totalDays = sstoi(_day);
    int month = sstoi(_month);
    int year = sstoi(_year);
    for (int i = 1; i < month; i++) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            totalDays += 31;
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            totalDays += 30;
        } else if (i == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                totalDays += 29;
            } else {
                totalDays += 28;
            }
        }
    }
    int dayOfWeek = (totalDays + (year - 1) + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;
    
    return dayOfWeek;
}

ostream& operator<<(ostream& os, const infor_call& a) {
    os << a.getNumber_phone() << " " << a.getMinute() << " " << a.getTime_start() << " " << a.getDay() << a.getRegion() << "\n";
    return os;
}