#include <iostream>
#include "ATM.h"

using namespace std;

int main(void) {
        ATM* my_ATM = new ATM();
        simul_ATM(my_ATM);

}

void simul_ATM (ATM *my_ATM) {
        bool play = true;
        while (play) {
                my_ATM->display_main_menu();
                int input_val;
                cin >> input_val;
        }
}