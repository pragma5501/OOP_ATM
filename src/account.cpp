#include <iostream>
#include "account.h"

using namespace std;

int Account::next_account_number = (ACCOUNT_NUMBER_BASE_OFFSET);

Account::Account (__account_param_t param)
{
        this->account_number = this->next_account_number++;
        this->password = param.password;
        this->user_id = param.user_id;
        this->owner = param.owner;
        this->my_bank = param.my_bank;

        this->balance = 0;
}

Account::~Account ()
{

}

void Account::diplay_account_info ()
{
        cout << "Account [";
        cout << "Bank: " << my_bank->get_bank_name() << ",";
        cout << "No: " << account_number << ",";
        cout << "Owner: " << owner->get_user_name() << "] ";
        cout << "balance: " << balance;
}