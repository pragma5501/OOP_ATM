#ifndef __USER_H__
#define __USER_H__

#include "ATM.h"
#include "bank.h"
#include "account.h"
#include "card.h"
#include "util.h"
#define MAX_NUM_ACCOUNT 10

class Account;
class Card;


class User{
private:
        string user_id;
        string user_name;

        Card* my_card;
        
protected:
        bool flag_admin;

public:
        User(string user_id, string user_name);
        ~User();

        void receive_card (Card* card);

        string get_user_name();
        bool get_flag_admin();

        
};

class Admin : public User {
private:
        Card* admin_card;

public:
        Admin(string user_id, string user_name);
        ~Admin();
};

#endif