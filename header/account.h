#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include "user.h"
#include "bank.h"
#include "util.h"
#include "card.h"

using namespace std;


class User;
class Bank;
class Card;

typedef struct __account_param_t{
        string account_number;
        string password;

        User* owner;
        Bank* my_bank;
} account_param_t;

class Account {
private:
        string account_number;
        string password;

        User* owner;
        Bank* my_bank;

        int balance;
public:
        Account(__account_param_t param);
        ~Account();
        void display_account_info ();

        void add_account_balance (int money);
        void minus_account_balance (int money);

        string get_password();
        string get_account_number ();
        int get_balance();

        Bank* get_bank();
        User* get_owner();
};


#endif