#ifndef __BANK_H__
#define __BANK_H__

#include <iostream>
#include <unordered_map>
#include "account.h"
#include "ATM.h"
#include "util.h"
#define MAX_NUM_ATM 10
#define MAX_NUM_ACCOUNTS 100

using namespace std;

class ATM;
class Account;

class Bank {
private:
        string name;
        
        unordered_map<int, ATM*> ATMs;
        unordered_map<string, Account*> accounts;
        
public:
        Bank(string bank_name);
        ~Bank();

        string get_bank_name();

        void deposit(ATM* target_ATM);
        void look_up_account_info(string account_number);

        bool flag_check_password(Account* user_account, string password);
        
        void display_bank_info();

        void push_ATM(ATM* my_ATM);
};


#endif