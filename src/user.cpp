#include "user.h"



User::User(string user_id, string user_name)
{
        this->user_id = user_id;
        this->user_name = user_name;

        this->flag_admin = false;
}

User::~User ()
{
        
}

void User::receive_card (Card* card)
{
        my_card = card;
}


string User::get_user_name ()
{
        return user_name;
}

bool User::get_flag_admin ()
{
        return flag_admin;
}

Admin::Admin (string user_id, string user_name) : User(user_id, user_name)
{
        this->flag_admin = true;
}
Admin::~Admin ()
{

}