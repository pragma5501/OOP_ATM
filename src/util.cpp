#include "util.h"

bool estimate_valid_check(int check)
{
        if (check >= 100000) return true;
        return false;
}

void display_cut_line()
{
        cout << endl;
        cout << "==================================" << endl;
}
void display_cut_line2()
{
        cout << endl;
        cout << "----------------------------------" << endl;
}
void display_error_line()
{
        cout << endl;
        cout << "!!------------------------------!!" << endl;
}

