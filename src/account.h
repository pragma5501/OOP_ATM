#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "user.h"
#include "bank.h"

#define ACCOUNT_NUMBER_BASE_OFFSET 100010001000

typedef struct __account_param_t{
        int password;

        int user_id;
        User* owner;
        Bank* my_bank;
} account_param_t;

class Account {
private:
        int account_number;
        int password;

        int user_id;
        
        User* owner;
        Bank* my_bank;

        int balance;
        static int next_account_number;
public:
        Account(__account_param_t param);
        ~Account();
        void diplay_account_info ();
}


#endif