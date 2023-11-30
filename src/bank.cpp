#include "bank.h"

Bank::Bank (string bank_name)
{
        this->name = bank_name;

        this->num_of_ATMs = 0;
        this->num_of_accounts = 0;
}

Bank::~Bank ()
{

}
ATM* Bank::find_ATM (int ATM_serial_number)
{
        for (int i = 0; i < num_of_ATMs; i++) {
                if (ATMs[i]->get_serial_number() != ATM_serial_number) continue;
                return ATMs[i];
        }

        cout << "Cannot find ATM" << endl;
        return (ATM*)0;
}

void Bank::deposit (int ATM_serial_number, int* cash)
{
        ATM* target_ATM = find_ATM(ATM_serial_number);
        if (target_ATM == (ATM*)0) {
                return;
        }
        
        target_ATM->receive_cash_available(cash);
}

void Bank::look_up_account_info (int account_number)
{
        Account* target_account = accounts[account_number];
        //Exception Handling Need.
        
        target_account->diplay_account_info();
}

