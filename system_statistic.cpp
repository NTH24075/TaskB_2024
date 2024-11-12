#include "system_statistic.h"

systemStatistic::systemStatistic() {
    customers_system.read_from_file();
    called_system.read_from_file();
}

void systemStatistic::getData() {
    Vector_build<infor_user> customers_vector = this->customers_system.getCustomer_list();
    Vector_build<infor_call> call_vector = this->called_system.getCall_list();

    for(int i = 0; i < customers_vector.size(); i++) {
        int fee = 0;
        string numberCus = customers_vector[i].getNumber_phone();
        numberCus.erase(0, 1);
        int num_NH = 0, num_LC = 0, num_X = 0, num_RX = 0;
        
        for(int j = 0; j < call_vector.size(); j++) {
            int heSoMien = 0;
            string numberCall = call_vector[j].getNumber_phone();
            if(numberCall == numberCus) {
                if(call_vector[j].getRegion() == " NH") {
                    num_NH++;
                    heSoMien = 1;
                }
                else if(call_vector[j].getRegion() == " LC") {
                    num_LC++;
                    heSoMien = 2;
                }
                else if(call_vector[j].getRegion() == " X") {
                    num_X++;
                    heSoMien = 3;
                }
                else {
                    num_RX++;
                    heSoMien = 4;
                }
            }
            int timeStartCall = sstoi(call_vector[j].getTime_start().substr(1,2));
            if(call_vector[i].getDayofWeek() == 0 || call_vector[i].getDayofWeek() == 6 
				|| timeStartCall >= 23 || timeStartCall <= 5)
                fee += 770 * call_vector[j].getMinute() * heSoMien;
            else
                fee += 1100 * call_vector[j].getMinute() * heSoMien;
        }
        
        statistic customer(customers_vector[i].getName(), customers_vector[i].getNumber_phone(), 
							fee, num_NH, num_LC, num_X, num_RX);
        statistic_system.add(customer);
    }    
}

void systemStatistic::run() {
    getData();
    statistic_system.write_to_file();
}
