#ifndef __MAIN_H__
#define __MAIN_H__

#include <iostream>
#include <unordered_map>
#include <cctype>
#include <random>
#include <numeric>
#include <string>
#include "header/ATM.h"
#include "header/bank.h"
#include "header/util.h"
#include "header/user.h"
#include "header/card.h"
#include "header/account.h"

#define MODE_CREATE_ATM 1
#define MODE_CREATE_ACCOUNT 2
#define MODE_ENTER_ATM_SESSION 3

#define MAX_NUM_ACCOUNT_PASSWORD 4



using namespace std;

class Bank;
class Account;
class Card;
class User;
class Admin;
class ATM;

void init_banks();
void init_users();
void display_create_ATMs();
void display_create_accounts();

int select_ATM();

void display_cut_line();
void display_cut_line2();
void display_error_line();

void destroy_maps () ;
void destroy_banks () ;
void destroy_users () ;
void destroy_ATMs () ;
void destroy_accounts () ;
void display_all_banks ();

Bank* enter_Bank();
User* enter_User();

string enter_account_password (Bank* bank, Account* account);
string create_account_password ();
string create_account_number();
void simul_ATM (ATM *my_ATM) ;

bool display_main_menu (ATM* my_ATM);
bool display_card_insert (ATM* my_ATM);
bool authorize_card (ATM* my_ATM, int card_number);

void display_card_password_checking(ATM* my_ATM, int i);
void display_flag_checking(ATM* my_ATM, bool flag_checking);
void display_ATM_fee_claim(ATM* my_ATM, int fee_money);

void display_ATM_session_menu(ATM* my_ATM);
void display_ATM_session_deposit(ATM* my_ATM);

void enter_ATM_session(ATM* my_ATM);
void enter_ATM_session_deposit(ATM* my_ATM);
bool enter_ATM_session_withdrawal(ATM* my_ATM);
bool enter_ATM_session_account_trans(ATM* my_ATM);
bool enter_ATM_session_cash_trans(ATM* my_ATM);


#endif