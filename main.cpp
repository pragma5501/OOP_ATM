#include <iostream>
#include <unordered_map>
#include "ATM.h"
#include "bank.h"

#define MODE_CREATE_ATM 1
#define MODE_CREATE_ACCOUNT 2

using namespace std;

unordered_map<string, Bank*> bank_map;
unordered_map<int, ATM*> ATM_map;

int main(void) {
        while(true) {
                cout << "1. Create ATMs" << endl;
                cout << "2. Create Accounts" << endl;
                
                int input;
                cin >> input;
                switch(input) {
                case MODE_CREATE_ACCOUNT:
                        display_create_ATMs();
                        break;
                case MODE_CREATE_ATM:
                        display_create_accounts();
                }
                
        }

}

void display_create_ATMs() {
        cout << "Enter the type_ATM" << endl;
        cout << "0. Single Bank" << endl;
        cout << "1. Multi Bank" << endl;
        int type_ATM;
        cin >> type_ATM;

        cout << "Enter the language of ATM" << endl;
        cout << "0. EN" << endl;
        cout << "1. KR" << endl;
        int type_lang;
        cin >> type_lang;


        cout << "Enter the primary bank name" << endl;
        string bank_name;
        cin >> bank_name;

        ATM* new_ATM = new ATM(type_ATM, type_lang, bank_map[bank_name]);

        while (true) {
                cout << "Enter the name of supported bank" << endl;
                cout << "0. Stop Enter the name of supported bank" << endl;
                cout << "Bank Name : ";
                
                cin >> bank_name;
                if (bank_name == "0") break;
                if (bank_map.find(bank_name) == bank_map.end()) {
                        cout << bank_name << " Bank : Not found" << endl;
                }
                new_ATM->push_bank(bank_map[bank_name]);
        }

        int serial_number = new_ATM->get_serial_number();
        ATM_map[serial_number] = new_ATM;
}

void display_create_accounts() {

}

void simul_ATM (ATM *my_ATM) {
        bool play = true;
        while (play) {
                my_ATM->display_main_menu();
                int input_val;
                cin >> input_val;
        }
}