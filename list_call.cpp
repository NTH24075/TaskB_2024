#include "list_call.h"

void List_call::read_from_file() {
    ifstream fileIn;
    fileIn.open("./cuocgoi.txt", ios::in);
    if (fileIn.is_open()) {
        string line;
        while (!fileIn.eof()) {
            getline(fileIn, line);
            if (line == "") {
                break;
            }
            stringstream ss(line);
            string phone;
            string time;
            string time_start;
            string date;
            string region;
            getline(ss, phone, ';');
            getline(ss, time, ';');
            getline(ss, time_start, ';');
            getline(ss, date, ';');
            getline(ss, region, ';');
            infor_call call(phone, stoi(time), time_start, date, region);
            call_list.push_back(call);
        }
    }
    fileIn.close();
}

Vector_build<infor_call> List_call::getCall_list() {
    return call_list;
}