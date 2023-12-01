#include "card.h"

int Card::next_card_number = 1000;

Card::Card (Bank* bank, User* owner, Account* account, string passcode)
{
        this->my_bank = bank;
        this->my_account = account;
        this->passcode = passcode;
        this->card_number = this->next_card_number++;
        this->owner = owner;

        display_cut_line2();
        cout << "Create Card Success!!" << endl;
        cout << this->owner->get_user_name() << "'s card number : " 
                << this->card_number << endl;

        
}

Card::~Card ()
{

}
void Card::send_card() 
{
        owner->receive_card(this);
}

int Card::get_card_number()
{
        return card_number;
}

Bank* Card::get_bank()
{
        return my_bank;
}

Account* Card::get_acount()
{
        return my_account;
}

