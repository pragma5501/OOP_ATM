#include <iostream>
#include "ATM.h"

using namespace std;

int ATM::next_serial_number = 100000;
int ATM::cash_scale[MAX_NUM_CASH_TYPE] = {1000, 5000, 10000, 50000};
int ATM::transaction_number = 0;

ATM::ATM(int type_ATM, int type_lang, Bank* primary_bank) {
        this->type_ATM = type_ATM;
        this->serial_number = this->next_serial_number++;
        this->type_lang = type_lang;
        this->cash_remained = 0;

        this->withdrawal_count = 0;

        this->primary_bank = primary_bank;
        banks[primary_bank->get_bank_name()] = primary_bank;


        for (int i = 0; i < MAX_NUM_CASH_TYPE; i++) {
                this->cash_available[i] = 1;
        }
        update_cash_available();
}

ATM::~ATM() {

}

bool ATM::check_card_valid (Card* card)
{
        Bank* bank_card = card->get_bank();
        string bank_name = bank_card->get_bank_name();

        if (banks.find(bank_name) == banks.end()) {
                return false;
        }

        return true;
}

void ATM::receive_cash_available (int* cash)
{
        
        for (int i = 0; i < MAX_NUM_CASH_TYPE; i++) {
                cash_available[i] += cash[i];
        }
        update_cash_available();
}
void ATM::update_cash_available ()
{
        cash_remained = 0;
        for (int i = 0; i < MAX_NUM_CASH_TYPE; i++) {
                cash_remained += cash_available[i] * cash_scale[i];
        }
}

int ATM::cal_fee(Bank* bank, Bank* target_bank, int type_transaction)
{
        bool flag_bank_primary = false;
        bool flag_target_bank_primary = false;

        if ( bank->get_bank_name() == primary_bank->get_bank_name()) {
                flag_bank_primary = true;
        }
        if ( target_bank->get_bank_name()== primary_bank->get_bank_name()) {
                flag_target_bank_primary = true;
        }
        
        switch(type_transaction) {
        case TYPE_TRANSACTION_DEPOSIT:
                if (flag_target_bank_primary == true) return 0;
                if (flag_target_bank_primary == false) return 1000;
                break;

        case TYPE_TRANSACTION_WITHDRAWAL:
                if (flag_target_bank_primary == true) return 1000;
                if (flag_target_bank_primary == false) return 2000;
                break;

        case TYPE_TRANSACTION_ACCOUNT_TRANS:
                if (flag_bank_primary & flag_target_bank_primary == true) 
                        return 2000;
                if (flag_bank_primary ^ flag_target_bank_primary == true)
                        return 3000;
                if (flag_bank_primary ^ flag_target_bank_primary == false)
                        return 4000;
                break;

        case TYPE_TRANSACTION_CASH_TRANS:
                return 5000;
                break;
        }
        return 0;
}

void ATM::push_bank (Bank* bank)
{
        if (type_ATM == (TYPE_BANK_SINGLE)) {
                cout << "Single ATM cannot attach several bank" << endl;
                return;
        }

        banks[bank->get_bank_name()] = bank;
        bank->push_ATM(this);
}

void ATM::display_ATM_info ()
{
        cout << "ATM";
        cout << "[SN: "<< serial_number << "]" << endl;
        cout << "Primary Bank : " << primary_bank->get_bank_name() << endl;
        cout << "remaining cash: " << cash_remained << endl;
}
void ATM::display_available_cash()
{
        display_cut_line();
        cout << "[Available cash]" << endl;
        for (int i =0; i < 4; i++) {
                cout << cash_scale[i] << ":" << cash_available[i] << endl;
        }
}

int ATM::get_type_ATM()
{
        return type_ATM;
}

int ATM::get_type_lang() 
{
        return type_lang;
}


int ATM::get_serial_number () 
{
        return serial_number;
}

Account* ATM::get_cur_account() 
{
        return cur_account;
}

bool ATM::update_withdrawal_count()
{
        withdrawal_count += 1;
        display_cut_line2();
        cout << "remain withdrawal count : " << 3 - withdrawal_count << endl;
        return true;
}
bool ATM::check_withdrawal_count()
{

        if (withdrawal_count >= 3) {
                return false;
        }
        return true;
}
bool ATM::reset_withdrawal_count()
{
        withdrawal_count = 0;
        return true;
}

void ATM::set_cur_account(Account* account)
{
        cur_account = account;
}


bool ATM::withdrawal_cash(int money) 
{
        int tmp_money = money;

        bool flag_withdrawal = check_withdrawal_count();
        if (flag_withdrawal == false) {
                cout << "Error : Available withdrawal is 3 per each session" << endl;
                return false;
        }

        if (money > 500000) {
                display_error_line();
                cout << "Error : The maximum amount of cash withdrawal per transaction is KRW 500,000" << endl;
                return false;
        }

        int cash_withdrawal[MAX_NUM_CASH_TYPE] = {0,0,0,0};
        for (int i = (MAX_NUM_CASH_TYPE) - 1; i >= 0 ; i--) {
                if( (int)(money / cash_scale[i]) <= cash_available[i] ) {
                        cash_withdrawal[i] = (int)(money / cash_scale[i]);
                        money -= cash_scale[i] * cash_withdrawal[i];
                } else {
                        cash_withdrawal[i] = cash_available[i];
                        money -= cash_scale[i] * cash_available[i];
                }
        }
        if (money != 0) {
                handle_error(ERROR_UNSUFFICIENT_CASH);
                return false;
        }

        int fee = cal_fee(primary_bank, cur_account->get_bank(), TYPE_TRANSACTION_WITHDRAWAL);
        cout << "Withdrawal Fee : " << fee << endl;

        if ( tmp_money + fee >cur_account->get_balance() ) {
                display_error_line();
                cout << "Error : Insufficient balance to claim" << endl;
                return false;
        }

        for (int i = 0; i < (MAX_NUM_CASH_TYPE); i++) {
                cash_available[i] -= cash_withdrawal[i];
                update_cash_available();
        }

        cash_remained += fee;
        
        cur_account->minus_account_balance(tmp_money + fee);
        display_ATM_info();

        update_withdrawal_count();
        display_available_cash();
        return true;
}


string ATM::make_transaction_history(transaction_hist_t* history)
{
        ostringstream oss;
        oss << "[Transaction ID : " << history->transaction_id << "]"<<endl;
        oss << "Transaction card bank  : " << history->card_bank_name << endl;
        oss << "Transaction card       : " << history->card_number << endl;
        oss << "Transaction type       : " << history->transaction_type << endl;
        oss << "Transaction Volume     : " << history->amount_cash << endl;
        
        transaction_history[history->transaction_id] = oss.str();

        return oss.str();;
}