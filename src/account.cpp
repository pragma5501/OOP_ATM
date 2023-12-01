#include <iostream>
#include "account.h"

using namespace std;


Account::Account (__account_param_t param)
{
        this->account_number = param.account_number;
        this->password = param.password;
        this->owner = param.owner;
        this->my_bank = param.my_bank;

        this->balance = 0;

        display_cut_line();
        cout << "Create Account Success!!" << endl;
        cout << this->owner->get_user_name() << "'s account number : " << this->account_number << endl;
}

Account::~Account ()
{

}

void Account::display_account_info ()
{
        cout << "Account [";
        cout << "Bank: " << my_bank->get_bank_name() << ", ";
        cout << "No: " << account_number << ", ";
        cout << "Owner: " << owner->get_user_name() << "] ";
        cout << "balance: " << balance << endl;
}

void Account::add_account_balance (int money)
{
        balance += money;
        display_account_info();
}
void Account::minus_account_balance (int money)
{
        balance -= money;
        display_account_info();
}

string Account::get_account_number ()
{
        return account_number;
}

string Account::get_password()
{
        return password;
}

Bank* Account::get_bank()
{
        return my_bank;
}
User* Account::get_owner()
{
        return owner;
}

int Account::get_balance()
{
        return balance;
}