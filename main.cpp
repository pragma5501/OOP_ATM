#include "main.h"

unordered_map<string, Bank*> bank_map;
unordered_map<int, ATM*> ATM_map;
unordered_map<string, User*> user_map;
unordered_map<string, Account*> account_map;
unordered_map<int, Card*> card_map;

int main(void) {
        init_banks();
        init_users();

        bool play = true;
        while(play) {
                display_cut_line();
                cout << "MODE : INIT ATMs & ACCOUNTs" << endl;
                cout << "Enter the CREATE MODE" << endl;
                cout << "1. Create ATMs" << endl;
                cout << "2. Create Accounts" << endl;
                cout << "3. Enter the ATM SESSION" << endl;
                int input;
                cin >> input;
                switch(input) {
                case MODE_CREATE_ATM:
                        display_create_ATMs();
                        break;
                case MODE_CREATE_ACCOUNT:
                        display_create_accounts();
                        break;
                case MODE_ENTER_ATM_SESSION:
                        play = false;
                        break;
                default:
                        display_cut_line2();
                        cout << "Please Input 1~3 value" << endl;
                }
                        
        }
        play = true;
        while (play) {
                display_cut_line();
                cout << "MODE : Select ATM" << endl;
                int serial_number = select_ATM();
                if (serial_number == -1) continue;

                simul_ATM(ATM_map[serial_number]);
                
        }


        destroy_maps();
}

void init_banks() {
        bank_map["Kakao"] = new Bank("Kakao"); 
        bank_map["Toss"] = new Bank("Toss");
        bank_map["KB"] = new Bank("KB");
        bank_map["Woori"] = new Bank("Woori");
}
void destroy_maps () 
{
        destroy_banks();
        destroy_users();
        destroy_ATMs();
        destroy_accounts();
}
void destroy_banks () 
{
        for (const auto& bank : bank_map) {
                delete bank.second;
        }
}
void destroy_users () 
{
        for (const auto& user : user_map) {
                delete user.second;
        }
}
void destroy_ATMs () 
{
        for (const auto& my_ATM : ATM_map) {
                delete my_ATM.second;
        }
}
void destroy_accounts () 
{
        for (const auto& account : account_map) {
                delete account.second;
        }
}

void display_all_banks ()
{
        cout << "Available Bank List" << endl;
        for (const auto& bank : bank_map) {
                bank.second->display_bank_info();
        }
}
void display_all_ATMs ()
{
        for (const auto& atm : ATM_map) {
                ATM* my_ATM = atm.second;
                my_ATM->display_ATM_info();
        }
}
void display_all_accounts ()
{
        for (const auto& account : account_map) {
                account.second->display_account_info();
        }
}

void init_users() 
{
        user_map["temo789"] = new User("temo789", "teemo");
        user_map["rust789"] = new User("rust789", "러스트");
}

void display_create_ATMs() 
{
        display_cut_line();
        cout << "MODE : CREATE_ATM" << endl;
        cout << "Enter the type_ATM" << endl;
        cout << "0. Single Bank" << endl;
        cout << "1. Multi Bank" << endl;
        int type_ATM;
        cin >> type_ATM;
        

        display_cut_line2();
        cout << "Enter the language of ATM" << endl;
        cout << "0. EN" << endl;
        cout << "1. KR" << endl;
        int type_lang;
        cin >> type_lang;



        display_cut_line2();
        cout << "Enter the primary bank name" << endl;
        Bank* primary_bank = enter_Bank();
        
        ATM* new_ATM = new ATM(type_ATM, type_lang, primary_bank);
        
        while (true) {
                if (type_ATM == (TYPE_BANK_SINGLE)) break;
                display_cut_line2();
                cout << "Enter the name of the supported bank" << endl;
                cout << "0. Stop Enter the name of the supported bank" << endl;
                display_all_banks();
                cout << "Bank Name : ";

                string bank_name;
                cin >> bank_name;
                if (bank_name == "0") break;

                // exception handling : Bank not found
                if (bank_map.find(bank_name) == bank_map.end()){
                        display_error_line();
                        cout << "ERROR : " << bank_name << " Bank Not found" << endl;
                        continue;
                }

                new_ATM->push_bank(bank_map[bank_name]);

        }
        primary_bank->deposit(new_ATM);


        int serial_number = new_ATM->get_serial_number();
        ATM_map[serial_number] = new_ATM;
        new_ATM->display_ATM_info();
}
void display_create_accounts() {
        display_cut_line();
        cout << "MODE : CREATE ACCOUNT" << endl;

        Bank* bank = enter_Bank();
        User* user = enter_User();
        string password = create_account_password();
        string account_number = create_account_number();

        __account_param_t account_info;
        account_info.my_bank = bank;
        account_info.owner = user;
        account_info.password = password;
        account_info.account_number = account_number;

        Account* new_account = new Account(account_info);
        account_map[new_account->get_account_number()] = new_account;
        new_account->display_account_info();

        Card* my_card = new Card(bank, user, new_account, password);
        card_map[my_card->get_card_number()] = my_card;

        
}

int select_ATM()
{
        cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        display_cut_line2();
        cout << "Available ATM" << endl;
        display_all_ATMs();

        display_cut_line2();
        cout << "Enter the Serial Number" << endl;
        cout << "Serial Number : ";
        int serial_number; 
        cin >> serial_number;

        if (ATM_map.find(serial_number) == ATM_map.end()) {
                display_error_line();
                cout << "Error : Invalid Serial Number" << endl;
                return -1;
        }
        return serial_number;
}

Bank* enter_Bank() 
{
        GOTO_ENTER_BANK:
        display_cut_line2();
        cout << "Enter the bank name" << endl;
        display_all_banks();
        string bank_name;
        cin >> bank_name;

        // exception handling : Bank not found
        if( bank_map.find(bank_name) == bank_map.end()){
                display_error_line();
                cout << "ERROR : " << bank_name << " Bank Not Found" << endl;
                goto GOTO_ENTER_BANK;
        }
        
        return bank_map[bank_name];
}
User* enter_User () 
{
        GOTO_FIND_USER:
        display_cut_line2();
        cout << "Enter the user id" << endl;
        string user_id;
        cin >> user_id;

        // exception handling : User not found
        if(user_map.find(user_id) == user_map.end()) {
                display_error_line();
                cout << "ERROR : " << user_id << " User Not Found" << endl;
                goto GOTO_FIND_USER;
        }

        return user_map[user_id];
}
string enter_account_password (Bank* bank, Account* account)
{
        string password;

        cout << bank->get_bank_name() << ":" << account->get_account_number() << endl;
        cout <<"Enter the" << "'s password" << endl;
        cin >> password;
        return password;
}

string create_account_password ()
{
        GOTO_CREATE_ACCOUNT_PASSWORD:
        display_cut_line2();
        string password;
        cout << "Enter New Account Password (password : 4-digit number)" << endl;
        cin >> password;

        bool flag = true;
        
        if (password.length() != (MAX_NUM_ACCOUNT_PASSWORD)) {
                flag = false;
        }
        for (int i = 0; i < password.length(); i++) {
                if (isdigit(static_cast<unsigned char>(password[i])) == 0) {
                        flag = false;
                        break;
                } 
        }

        if (flag == false) {
                display_error_line();
                cout << "Cannot fit to password criteria" << endl;
                goto GOTO_CREATE_ACCOUNT_PASSWORD;
        }

        return password;
}
string create_account_number ()
{
        GOTO_CREATE_ACCOOUNT_NUMBER:
        display_cut_line2();
        cout << "Enter New Account Number(12-digit)" << endl;
        cout << "Fromat : xxxxxxxxxxxx" << endl;
        cout << "Account Number : ";

        string account_number;
        cin >> account_number;
        if (account_number.length() != 12) {
                display_error_line();
                cout << "Invalid Account Number" << endl;
                goto GOTO_CREATE_ACCOOUNT_NUMBER;
        }
        if (account_map.find(account_number) != account_map.end() ) {
                display_error_line();
                cout << "Already exist account number" << endl;
                goto GOTO_CREATE_ACCOOUNT_NUMBER;
        }

        return account_number;
}

void simul_ATM (ATM *my_ATM) 
{
        bool play = true;
        while (play) {
                play = display_main_menu(my_ATM);
        }
}

bool display_main_menu (ATM* my_ATM)
{
        display_cut_line2();
        cout << "Welcome" << endl;
        cout << "To start, please insert your debit card" << endl;

        display_cut_line();
        cout << "1. Card Insert" << endl;
        cout << "2. Recipt Print" << endl;
        cout << "E. Cancle" << endl;
        int click_data;
        cin >> click_data;
        

        switch (click_data) {
        case MODE_CARD_INSERT:
                display_card_insert(my_ATM);
                break;
        case MODE_PRINT_RECEIPT:
                break;
        case MODE_CANCEL:
                return false;
                break;
        default:
                return false;
                break;
        }
}

bool display_card_insert (ATM* my_ATM)
{
        GOTO_END_SESSION:
        display_cut_line2();
        cout << "Enter the card number" << endl;
        cout << "Card Number : ";

        int card_number;
        cin >> card_number;
        

        bool flag_card_valid = authorize_card(my_ATM, card_number);
        if (flag_card_valid == false) {
                my_ATM->handle_error(ERROR_INVALID_AUTHORIZE_CARD);
                return false;
        }

        Account* cur_account = card_map[card_number]->get_acount();
        my_ATM->set_cur_account(cur_account);

        enter_ATM_session(my_ATM);
        return true;
}
bool authorize_card (ATM* my_ATM, int card_number)
{
        if (card_map.find(card_number) == card_map.end()) {
                my_ATM->handle_error(ERROR_UNEXIST_CARD_NUMBER);
                return false;
        } 

        bool flag_card_valid = my_ATM->check_card_valid(card_map[card_number]);
        if (flag_card_valid == false) {
                my_ATM->handle_error(ERROR_INVALID_CARD_INSERT);
                return false;
        }
        for (int i = 0; i < 3; i++) {
                display_card_password_checking(my_ATM, 2 - i);
                string password;
                cin >> password;

                Bank* card_bank = card_map[card_number]->get_bank();
                Account* card_account = card_map[card_number]->get_acount();
                bool flag_checking = card_bank->flag_check_password(card_account, password);
                display_flag_checking(my_ATM, flag_checking);

                if (flag_checking == true) {
                        return true;
                }
        }
        return false;


}

void display_card_password_checking(ATM* my_ATM, int i) {
        cout << "Enter the card password(Remain opportunity : " 
                << i << ")" << endl;
        cout << "Password : ";
}
void display_flag_checking(ATM* my_ATM, bool flag_checking) {
        if (flag_checking == true) {
                cout << "Correct Password!!" << endl;
                return;
        }
        cout << "Incorrect Password :(" << endl;
}

void enter_ATM_session(ATM* my_ATM) 
{
        my_ATM->reset_withdrawal_count();

        while (true) {
                display_ATM_session_menu(my_ATM);

                string mode_transaction;
                cin >> mode_transaction;
                
                if (mode_transaction == "e") {
                        display_error_line();
                        cout << "Keybard Interrupt : End Session" << endl;
                        return;
                }
                if (mode_transaction == "a") {
                        display_all_ATMs();
                        continue;
                }
                if (mode_transaction == "b") {
                        display_all_accounts();
                        continue;
                }
                int mode = stoi(mode_transaction);
                switch(mode) {
                case MODE_DEPOSIT:
                        enter_ATM_session_deposit(my_ATM);
                        break;
                case MODE_WITHDRAWAL:
                        enter_ATM_session_withdrawal(my_ATM);
                        break;
                case MODE_ACCOUNT_TRANS:
                        break;
                case MODE_CASH_TRANS:
                        break;
                default:
                        return;
                }
 
        }
        
}

void enter_ATM_session_deposit(ATM* my_ATM)
{
        display_ATM_session_deposit(my_ATM);
        int cash_1000, cash_5000, cash_10000, cash_50000;
        cin >> cash_1000 >> cash_5000 >> cash_10000 >> cash_50000;

        bool flag_valid_checks = true;

        int check;
        vector<int> checks;
        
        while (cin >> check) {
                if (check == -1) break;
                if (check < 100000) {
                        my_ATM->handle_error(ERROR_DEPOSIT_INVALID_CHECK);
                        return;
                }
                checks.push_back(check);
        }
        
        int sum_num_cashes = cash_1000 + cash_5000 + cash_10000 + cash_50000;
        if (sum_num_cashes > (LIMIT_DEPOSIT_CASH) || checks.size() > (LIMIT_DEPOSIT_CHECKS)) {
                my_ATM->handle_error(ERROR_DEPOSIT_LIMIT_EXCEEDS);
                return;
        }
        Account* cur_account = my_ATM->get_cur_account();

        int fee_money = my_ATM->cal_fee(my_ATM->get_primary_bank(), cur_account->get_bank(), TYPE_TRANSACTION_DEPOSIT);

        display_ATM_fee_claim(my_ATM, fee_money);
        
        int cash_list[MAX_NUM_CASH_TYPE] = {cash_1000, cash_5000, cash_10000, cash_50000};
        int money = 0;
        for (int i = 0; i < MAX_NUM_CASH_TYPE; i++) {
                money += cash_list[i] * my_ATM->cash_scale[i];
        }
        money += accumulate(checks.begin(), checks.end(), 0);

        if (fee_money == 1000) {
                cash_list[0] += 1;
        }
        my_ATM->receive_cash_available(cash_list);

        

        cur_account->add_account_balance(money);
        my_ATM->display_available_cash();

        

}
bool enter_ATM_session_withdrawal(ATM* my_ATM)
{
        display_cut_line2();
        cout << "Enter the amount of fund to withdrawal" << endl;
        int money_hope;
        cin >> money_hope;

        my_ATM->withdrawal_cash(money_hope);
        
}
bool enter_ATM_session_account_trans(ATM* my_ATM)
{
        
}
bool enter_ATM_session_cash_trans(ATM* my_ATM)
{
        
}


void display_ATM_session_menu(ATM* my_ATM)
{
        display_cut_line();
        cout << "MODE : ATM SESSION" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdrawal" << endl;
        cout << "3. Transfer" << endl;
}
void display_ATM_session_deposit(ATM* my_ATM)
{
        cout << "Enter the Deposit Cash" << endl;
        cout << "Format : 1000 5000 10000 50000 check1 .. check_n -1" << endl;
        cout << "Example) Cash : 0 1 1 0 100100" << endl;
        cout << "Cash";
}

void display_ATM_fee_claim(ATM* my_ATM, int fee)
{
        display_cut_line2();
        cout << "Fee claimed : KRW " << fee << endl;
        cout << "Enter any key : auto claim" << endl;
        string dummy;
        cin >> dummy;
}

