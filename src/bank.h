#ifndef __BANK_H__
#define __BANK_H__

#include <iostream>
#include "user.h"
#include "ATM.h"

#define MAX_NUM_ATM 10
#define MAX_NUM_ACCOUNTS 100

using namespace std;

class Bank {
private:
        string name;

        int num_of_ATMs;
        ATM* ATMs[MAX_NUM_ATM];

        int num_of_accounts;
        Account* accounts[MAX_NUM_ACCOUNTS];
        
public:
        Bank(string bank_name);
        ~Bank();

        void get_bank_name();

        ATM* find_ATM(int ATM_serial_number);
        void deposit(int ATM_serial_number, int* cash);
        void look_up_account_info(int account_number);
}


#endif