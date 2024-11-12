#include "list_customer.h"

void List_customer::read_from_file() {
    ifstream fileIn;
    fileIn.open("./khachhang.txt", ios::in);
    if (fileIn.is_open()) {
        string line;
        while (!fileIn.eof()) {
            getline(fileIn, line);
            if (line == "") {
                break;
            }
            stringstream ss(line);
            string fName;
            string nPhone;
            getline(ss, fName, ';');
            getline(ss, nPhone, ';');
            infor_user customer(fName, nPhone);
            customers_list.push_back(customer);
        }
    }
    fileIn.close();
}

Vector_build<infor_user> List_customer::getCustomer_list() {
    return customers_list;
}