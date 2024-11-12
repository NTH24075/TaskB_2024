#include "statistic.h"

statistic::statistic(string name, string number_phone, int call_fee, int number_NH, 
						int number_LC, int number_X, int number_RX) {
    this->name = name;
    this->number_phone = number_phone;
    this->call_fee = call_fee;
    this->number_NH = number_NH;
    this->number_LC = number_LC;
    this->number_X = number_X;
    this->number_RX = number_RX;
}

string statistic::getName() {
    return this->name;
}

string statistic::getNumber_phone() {
    return this->number_phone;
}

int statistic::getCall_fee() {
    return this->call_fee;
}

int statistic::getNumber_NH() {
    return this->number_NH;
}

int statistic::getNumber_LC() {
    return this->number_LC;
}

int statistic::getNumber_X() {
    return this->number_X;
}

int statistic::getNumber_RX() {
    return this->number_RX;
}
