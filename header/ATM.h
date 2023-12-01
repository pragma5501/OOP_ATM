#ifndef __ATM_H__
#define __ATM_H__

#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include "user.h"
#include "bank.h"
#include "card.h"
#include "util.h"

#define MAX_NUM_BANK_SUPPORTED 10

#define TYPE_BANK_SINGLE 0
#define TYPE_BANK_MULTI 1

#define TYPE_LANG_KR 0
#define TYPE_LANG_EN 1

#define TYPE_FEE_DEPOSIT 0
#define TYPE_FEE_WITHDRAWAL 1
#define TYPE_FEE_ACCOUNT_TRANS 2
#define TYPE_FEE_CASH_TRANS 3

#define TYPE_TRANSACTION_DEPOSIT 0
#define TYPE_TRANSACTION_WITHDRAWAL 1
#define TYPE_TRANSACTION_ACCOUNT_TRANS 2
#define TYPE_TRANSACTION_CASH_TRANS 3

#define ERROR_INVALID_CARD_INSERT 0
#define ERROR_INVALID_AUTHORIZE_CARD 1
#define ERROR_DEPOSIT_LIMIT_EXCEEDS 2
#define ERROR_DEPOSIT_INVALID_CHECK 3
#define ERROR_UNEXIST_CARD_NUMBER 4
#define ERROR_UNSUFFICIENT_CASH 5

#define MODE_CARD_INSERT 1
#define MODE_PRINT_RECEIPT 2
#define MODE_CANCEL 3

#define MODE_DEPOSIT 1
#define MODE_WITHDRAWAL 2
#define MODE_ACCOUNT_TRANS 3
#define MODE_CASH_TRANS 4
#define MODE_INTERRUPT 

#define LIMIT_DEPOSIT_CASH 50
#define LIMIT_DEPOSIT_CHECKS 30

#define MAX_NUM_CASH_TYPE 4

#define CASH_1000 0
#define CASH_5000 1
#define CASH_10000 2
#define CASH_50000 3


#define ERROR_MAIN_MENU_INVALID_CLICK 0

using namespace std;

class User;
class Bank;
class Card;

typedef struct __transaction_hist_t {
        int transaction_id;
        int card_number;
        string transaction_type;
        int amount_cash;
        string card_bank_name;

} transaction_hist_t;

class ATM {
private:
        int type_ATM;
        int type_lang;
        int cash_remained;
        int serial_number; // 6-digit serial number : unique

        Bank* primary_bank;

        unordered_map <string, Bank*> banks;
        unordered_map <int, string> transaction_history;
        
        int cash_available[MAX_NUM_CASH_TYPE];

        Account* cur_account;
        int withdrawal_count;
        
        static int next_serial_number;
        static int transaction_number;

public:
        static int cash_scale[MAX_NUM_CASH_TYPE];

        ATM (int type_ATM, int type_lang, Bank* primary_bank);
        ~ATM ();
        bool check_card_valid (Card* card);
        void receive_cash_available (int* cash);
        void update_cash_available ();
        
        int cal_fee(Bank* bank, Bank* target_bank, int type_transaction);

        void push_bank (Bank* bank);

        void display_ATM_info ();
        void display_available_cash();

        int get_type_ATM();
        int get_type_lang();
        int get_serial_number();
        Account* get_cur_account();
        Bank* get_primary_bank() {return primary_bank;};

        int get_transaction_id();

        bool check_withdrawal_count();
        bool update_withdrawal_count();
        bool reset_withdrawal_count();
        void set_cur_account(Account* account);
        
        void handle_error(int _TYPE_ERROR);  

        bool withdrawal_cash(int money);

        string make_transaction_history(transaction_hist_t* history);
};



#endif

        
