#include "list_statistic.h"

void List_statistic::add(statistic object) {
    statistic_list.push_back(object);
}

void List_statistic::write_to_file() {
    ofstream fileOut;
    fileOut.open("./ketqua.txt", ios::out);
    if (fileOut.is_open()) {
        fileOut << std::left
                << "|" << std::setw(30) << "Full Name"
                << "|" << std::setw(15) << "NumberPhone"
                << "|" << std::setw(15) << "Total_FEE"
                << "|" << std::setw(10) << "number_NH"
                << "|" << std::setw(10) << "number_LC"
                << "|" << std::setw(10) << "number_X"
                << "|" << std::setw(10) << "number_RX"
                << "|\n";
        fileOut << "|------------------------------|---------------|---------------|----------|----------|----------|----------|\n";
        for (int i = 0; i < statistic_list.size(); i++) {
            fileOut << "|" << std::setw(30) << std::left << statistic_list[i].getName();
            fileOut << "|" << std::setw(15) << std::right << statistic_list[i].getNumber_phone().substr(1, 10);
            fileOut << "|" << std::setw(15) << std::right << statistic_list[i].getCall_fee();
            fileOut << "|" << std::setw(10) << std::right << statistic_list[i].getNumber_NH();
            fileOut << "|" << std::setw(10) << std::right << statistic_list[i].getNumber_LC();
            fileOut << "|" << std::setw(10) << std::right << statistic_list[i].getNumber_X();
            fileOut << "|" << std::setw(10) << std::right << statistic_list[i].getNumber_RX();
            fileOut << "|\n";

            fileOut << "|------------------------------|---------------|---------------|----------|----------|----------|----------|\n";
        }
    }
    fileOut.close();
}