#ifndef __CARD_H__
#define __CARD_H__


#include <iostream>
#include "bank.h"
#include "account.h"

using namespace std;

class Card {
private:
        Bank* my_bank;
        Account* my_account;

        int card_number;
        int passcode;
        static int next_card_number;
public:
        Card();
        ~Card();

        int get_card_number();
        Bank* get_bank();
        Account* get_acount();
}

#endif