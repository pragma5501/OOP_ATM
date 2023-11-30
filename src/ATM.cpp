#include "ATM.h"
#include <iostream>

using namespace std;

int ATM::next_serial_number = 100000;
int ATM::cash_scale[MAX_NUM_CASH_TYPE] = {1000, 5000, 10000, 50000};

ATM::ATM(int type_ATM, int type_lang, Bank* primary_bank) {
        this->type_ATM = type_ATM;
        this->serial_number = this->next_serial_number++;
        this->type_lang = type_lang;
        this->cash_remained = 0;

        this->primary_bank = primary_bank;
        
        for (int i = 0; i < MAX_NUM_CASH_TYPE; i++) {
                cash_available[i] = 0;
        }

}

ATM::~ATM() {
        
}

bool ATM::check_card_valid (Card* card)
{
        Bank* bank_card = card->get_bank();
        for (int i = 0; i < num_of_banks; i++) {
                if ( bank_card != banks[i]) continue;

                return true;
        }

        return false;
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
        for (int i = 0; i < MAX_NUM_CASH_TYPE; i++) {
                cash_remained += cash_available[i] * cash_scale[i];
        }
}

void ATM::display_ATM_info ()
{
        cout << "ATM";
        cout << "[SN: "<< serial_number << "]";
        cout << "remaining cash: " << cash_remained;
        cout << endl;
}

void ATM::display_main_menu ()
{
        if (this->type_lang == (TYPE_LANG_EN)) {
                display_main_menu_EN();
        }
}
void ATM::display_card_insert ()
{
        if (this->type_lang == (TYPE_LANG_EN)) {
                display_card_insert_EN();
        }
}




void display_main_menu_EN ()
{
        cout << "Welcome" << endl;
        cout << "To start, please insert your debit card" << endl;
        cout << "============================================" << endl;
        cout << "1. Cash/Check Insert and Dispenser" << endl;
        cout << "2. Card Insert" << endl;
        cout << "3. Recipt Print" << endl;
}

void display_card_insert_EN ()
{
        cout << "Enter the card number" << endl;

}

