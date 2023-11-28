#include <iostream>
#include "account.h"

using namespace std;

Account::Account (__account_param_t param)
{
        account_number = param.account_number;
        password = param.password;
        user_id = param.user_id;
        owner = param.owner;
        my_bank = param.my_bank;

        balance = 0;
}

Account::~Account ()
{

}

void Account::diplay_account_info ()
{
        cout << "Account [";
        cout << "Bank: " << my_bank.get_bank_name() << ",";
        cout << "No: " << account_number << ",";
        cout << "Owner: " << owner.get_user_name() << "] ";
        cout << "balance: " << balance;
}