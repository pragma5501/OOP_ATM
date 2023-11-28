#ifndef __ATM_H__
#define __ATM_H__
#include "user.h"
#include "bank.h"


#define TYPE_BANK_SINGLE 0
#define TYPE_BANK_MULTI 1

#define TYPE_LANG_KR 0
#define TYPE_LANG_EN 1

#define TYPE_FEE_DEPOSIT 0
#define TYPE_FEE_WITHDRAW 1
#define TYPE_FEE_ACCOUNT_TRANS 2
#define TYPE_FEE_CASH_TRANS 3

using namespace std;

class ATM {
private:
        int type_ATM;
        int type_lang;
        int cash_remained;
        int serial_number; // 6-digit serial number : unique

        static int next_serial_number = 100000;

public:
        ATM ();
        ~ATM ();
        void display_ATM_info ();
        void display_main_menu ();
        void display_card_insert ();

        
}


#endif

        
