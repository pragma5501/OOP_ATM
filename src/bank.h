#ifndef __BANK_H__
#define __BANK_H__

#include <iostream>
#include "user.h"
#include "ATM.h"

using namespace std;

class Bank {
private:
        string name;
        
public:
        Bank(string bank_name);
        ~Bank();

        void deposit();
        void get_bank_name();

}


#endif