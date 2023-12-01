#ifndef __CARD_H__
#define __CARD_H__


#include <iostream>
#include "bank.h"
#include "account.h"
#include "user.h"
#include "util.h"
using namespace std;

class Bank;
class Account;
class User;

class Card {
private:
        User* owner;
        Bank* my_bank;
        Account* my_account;

        int card_number;
        string passcode;
        static int next_card_number;
public:
        Card(Bank* bank, User* owner, Account* account, string passcode);
        ~Card();

        void send_card();

        int get_card_number();
        Bank* get_bank();
        Account* get_acount();

};

#endif