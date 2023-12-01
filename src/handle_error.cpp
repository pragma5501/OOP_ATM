#include <iostream>
#include "ATM.h"

using namespace std;


void ATM::handle_error(int _TYPE_ERROR)
{
        switch(_TYPE_ERROR) {
        case ERROR_INVALID_CARD_INSERT:
                display_error_line();
                cout << "Error : Invalid Card(Not Suported Bank)" << endl;
                break;
        case ERROR_INVALID_AUTHORIZE_CARD:
                display_error_line();
                cout << "Error : Invalid ATM session" << endl;
                cout << "Card Returned" << endl;
                break;
        case ERROR_UNEXIST_CARD_NUMBER:
                display_error_line();
                cout << "Error : Canot Find Card Number" << endl;
                break;
        case ERROR_UNSUFFICIENT_CASH:
                display_error_line();
                cout << "Error : Insufficient Fund to withdrawal" << endl;
                break;
        case ERROR_DEPOSIT_LIMIT_EXCEEDS:
                display_error_line();
                cout << "Error : Exceeds cash or check amount" << endl;
                break;
        case ERROR_DEPOSIT_INVALID_CHECK:
                display_error_line();
                cout << "Error : Invalid Check input" << endl;

        }

        
}