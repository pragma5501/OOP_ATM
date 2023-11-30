#ifndef __ATM_H__
#define __ATM_H__
#include <iostream>
#include "user.h"
#include "bank.h"
#include "card.h"

#define MAX_NUM_BANK_SUPPORTED 10

#define TYPE_BANK_SINGLE 0
#define TYPE_BANK_MULTI 1

#define TYPE_LANG_KR 0
#define TYPE_LANG_EN 1

#define TYPE_FEE_DEPOSIT 0
#define TYPE_FEE_WITHDRAW 1
#define TYPE_FEE_ACCOUNT_TRANS 2
#define TYPE_FEE_CASH_TRANS 3

#define MAX_NUM_CASH_TYPE 4

#define CASH_1000 0
#define CASH_5000 1
#define CASH_10000 2
#define CASH_50000 3

using namespace std;


class ATM {
private:
        int type_ATM;
        int type_lang;
        int cash_remained;
        int serial_number; // 6-digit serial number : unique

        Bank* primary_bank;

        int num_of_banks;
        Bank* banks[MAX_NUM_BANK_SUPPORTED];
        
        int cash_available[MAX_NUM_CASH_TYPE];

        static int cash_scale[MAX_NUM_CASH_TYPE];
        static int next_serial_number;

public:
        ATM (int type_ATM, int type_lang, Bank* primary_bank);
        ~ATM ();
        bool check_card_valid (Card* card);
        void receive_cash_available (int* cash);
        void update_cash_available ();
        
        void push_bank ();

        void display_ATM_info ();
        void display_main_menu ();
        void display_card_insert ();

        int get_serial_number();
        
}


#endif

        
