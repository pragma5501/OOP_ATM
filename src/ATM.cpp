#include "ATM.h"
#include <iostream>

using namespace std;

ATM::ATM(int type_ATM, int type_lang) {
        
}

ATM::~ATM() {
        
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