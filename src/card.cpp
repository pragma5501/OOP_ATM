#include "card.h"

int Card::next_card_number = 1000;

Card::Card (Bank* bank, Account* account, int passcode)
{
        this->my_bank = bank;
        this->my_account = account;
        this->passcode = passcode;
        this->card_number = this->next_card_number++;
}

Card::~Card ()
{

}