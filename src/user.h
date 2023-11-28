#ifndef __USER_H__
#define __USER_H__

#include "ATM.h"
#include "bank.h"
#include "account.h"

#define MAX_NUM_ACCOUNT 10

class User {
private:
        Account my_accounts[MAX_NUM_ACCOUNT];
        
public:
        User();
        ~User();
        void get_user_name();
}


#endif