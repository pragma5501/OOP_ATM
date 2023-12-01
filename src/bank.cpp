#include "bank.h"

Bank::Bank (string bank_name)
{
        this->name = bank_name;
}

Bank::~Bank ()
{

}

string Bank::get_bank_name()
{
        return name;
}




void Bank::deposit (ATM* target_ATM)
{
        display_cut_line();
        cout << "Primary Bank : Enter the amoount of fund to deposit to ATM" << endl;
        cout << "Example) 1 1 0 1" << endl;
        cout << "-> 1000 + 5000 + 10000 * 0 + 50000 = 56000" << endl;
        cout << "Cash : ";
        int cash[4];
        cin >> cash[0] >> cash[1] >> cash[2] >> cash[3];
        
        target_ATM->receive_cash_available(cash);
}

void Bank::look_up_account_info (string account_number)
{
        Account* target_account = accounts[account_number];
        //Exception Handling Need.
        
        target_account->display_account_info();
}

bool Bank::flag_check_password(Account* user_account, string password)
{
        if (user_account->get_password() == password) return true;
        return false;
}

void Bank::display_bank_info ()
{
        cout << "[Bank : " << name << "]"<< endl;
}

void Bank::push_ATM(ATM* my_ATM) 
{
        ATMs[my_ATM->get_serial_number()] = my_ATM;
}
