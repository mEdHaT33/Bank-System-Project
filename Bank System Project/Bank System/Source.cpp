#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> //(***)
#include <limits> //limit letters in switch
#include <iomanip> //list width

using namespace std;

char user[25], pass[25], fn[25], ln[25], un[25], pd[25], an[25], acn[25], bl[25], em[40];

int Welcome(void);
void Main_Menu();
bool Login();
void Admin_Menu();
void Add_New_Account();
void Modify_An_Account();
void Close_An_Account();
void List_All_Accounts();
void User_Menu();
void Balance_Enquiry();
void Withdraw_Amount();
void Deposit_Amount();
void Transfer_Amount();

int main(void)
{
    Welcome();
}

int Welcome(void)
{
    int wel_close = 1;
    int wel_choice;
    while (wel_close < 4)
    {
        cout << "*** Welcome to our Bank ***\n\n";
        if (wel_close > 1)
            cout << "Attempt " << wel_close << ".\n\n";
        if (wel_close == 3)
        {
            cout << "If You Entered This Attemp Wrong the Program Will Close.\n \n";
        }
        cout << "Please choose 1 or 2.\n" << endl;
        cout << "1. Login\n" << "2. Register as a Client\n\n";
        cout << "Your Choice: ";
        cin >> wel_choice;
        switch (wel_choice)
        {
        case 1:
            system("cls");
            Main_Menu();
            break;
        case 2:
            system("cls");
            cout << "Register\n\n";
            Add_New_Account();
            break;
        default:
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "\nInvalid Input!\n";
            if (wel_close < 3)
            {
                cout << "Please type 1 or 2 ONLY.\n";
                system("pause");
                system("cls");
            }
            wel_close++;
            break;
        }
    }
    system("pause");
    system("cls");
    cout << "Thank You For Using Our Program.\n";
    return 0;
}

void Main_Menu()
{
    fstream account;
    account.open("account.txt", ios::in);
    cin.ignore();
    int close = 1;
    while (close < 4)
    {
        cout << "Login\n\n";
        if (close > 1)
            cout << "Attempt " << close << ".\n\n";
        cout << "Please Enter Your Username and Password.\n \n";
        if (Login())
        {
            User_Menu();
            break;
        }
        else
        {
            cout << "\n\nIncorrect Username or Password.";
            if (close < 3)
                cout << "\nPlease, Retry the Login.\n";
            else if (close == 3)
                cout << "\nYou Will Return To Main Menu Page.\n";
            system("pause");
            system("cls");
            close++;
        }
    }
    account.close();
}

bool Login()
{
    int Length = 0;
    char Temp;
    cout << "Username: ";
    cin.getline(user, 25);
    cout << "Password: ";
    while (true)
    {
    pwd:
        Temp = _getch();
        if (Temp == 13)
        {
            break;
        }
        else if (Length == 0 && Temp == 8)
        {
            goto pwd;
        }
        else if (Temp == 8)
        {
            cout << "\b \b";
            Length--;
        }
        else
        {
            pass[Length] = Temp;
            Length++;
            cout << "*";
            pass[Length] = pass[24];
        }
    }
    if (strcmp("admin", user) == 0 && strcmp("admin", pass) == 0)
    {
        Admin_Menu();
    }
    if (strlen(user) == 0 || strlen(pass) == 0)
    {
        return false;
    }
    else
    {
        fstream account;
        account.open("account.txt", ios::in);
        while (!account.eof())
        {
            account.getline(fn, 25, '|');
            account.getline(ln, 25, '|');
            account.getline(un, 25, '|');
            account.getline(pd, 25, '|');
            account.getline(an, 25, '|');
            account.getline(bl, 25, '|');
            account.getline(em, 40);
            if (strcmp(un, user) == 0 && strcmp(pd, pass) == 0)
                return true;
            else if (strlen(user) == 0 || strlen(pass) == 0)
            {
                return false;
            }
            else if (!account)
            {
                return false;
            }
        }
    }
    return false;
}

void Admin_Menu()
{
    int ad_choice;
    system("cls");
    cout << "Hi Admin.\n\n";
    cout << "Please choose a number from 1 to 5.\n" << endl;
    cout << "1. Add New Account" << endl << "2. Modify An Account" << endl;
    cout << "3. Close An Account" << endl << "4. List All Account" << endl;
    cout << "5. Log out\n" << endl;
choice:
    cout << "Your Choice: ";
    cin >> ad_choice;
    switch (ad_choice)
    {
    case 1:
        system("cls");
        cout << "Creating a New Account.\n\n";
        Add_New_Account();
        break;
    case 2:
        system("cls");
        cout << "Modifying an Account.\n\n";
        Modify_An_Account();
        break;
    case 3:
        system("cls");
        cout << "Closing an Account.\n\n";
        Close_An_Account();
        break;
    case 4:
        system("cls");
        cout << "Accounts List.\n\n";
        List_All_Accounts();
        break;
    case 5:
        cout << "\nYou have logged out from your account.\n";
        system("pause");
        system("cls");
        Welcome();
        break;
    default:
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "\nIncorrect Number\n";
        cout << "Please type 1, 2, 3, 4, 5 ONLY.\n\n";
        goto choice;
    }
}

void Add_New_Account()
{
    fstream account;
    account.open("account.txt", ios::app);
    cin.ignore();
    cout << "First Name: ";
    cin.getline(fn, 25);
    cout << "Last Name: ";
    cin.getline(ln, 25);
    cout << "User Name: ";
    cin.getline(un, 25);
    cout << "Password: ";
    cin.getline(pd, 25);
    cout << "Account Number: ";
    cin.getline(an, 25);
    cout << "Balance: ";
    cin.getline(bl, 25);
    cout << "E-mail: ";
    cin.getline(em, 40);
    account << fn << '|' << ln << '|' << un << '|' << pd << '|' << an << '|' << bl << '|' << em << '\n';
    account.close();
    cout << "\nDone!\n\n";
    if (strcmp("admin", user) == 0 && strcmp("admin", pass) == 0)
    {
        cout << "You Will Return To Admin Menu Page.\n";
        system("pause");
        system("cls");
        Admin_Menu();
    }
    else
    {
        cout << "\nYou Will Return To Main Menu Page.\n";
        system("pause");
        system("cls");
        Welcome();
    }
}

void Modify_An_Account()
{
    int mod = 0;
    fstream account;
    fstream temp;
    account.open("account.txt", ios::in);
    temp.open("temp.txt", ios::out);
    cin.ignore();
    cout << " \nEnter Account Number: ";
    cin.getline(acn, 25);
    if (strcmp("", acn) == 0 || !account)
    {
        cout << "\nNo Account Number Entered\n";
        cout << "\nYou Will Return To Admin Menu Page.\n";
        system("pause");
        system("cls");
        Admin_Menu();
    }

    while (!account.eof())
    {
        account.getline(fn, 25, '|');
        account.getline(ln, 25, '|');
        account.getline(un, 25, '|');
        account.getline(pd, 25, '|');
        account.getline(an, 25, '|');
        account.getline(bl, 25, '|');
        account.getline(em, 40);
        if (strcmp(an, acn) == 0)
        {
            cout << "\nEnter The New Data.\n\n";
            cout << "First Name: ";
            cin.getline(fn, 25);
            cout << "Last Name: ";
            cin.getline(ln, 25);
            cout << "User Name: ";
            cin.getline(un, 25);
            cout << "Password: ";
            cin.getline(pd, 25);
            cout << "Balance: ";
            cin.getline(bl, 25);
            cout << "E-mail: ";
            cin.getline(em, 40);
            temp << fn << '|' << ln << '|' << un << '|' << pd << '|' << an << '|' << bl << '|' << em << '\n';
            mod = 1;
        }
        else
        {
            temp << fn << '|' << ln << '|' << un << '|' << pd << '|' << an << '|' << bl << '|' << em << '\n';
        }

    }
    temp.close();
    account.close();
    account.open("account.txt", ios::out);
    temp.open("temp.txt", ios::in);
    while (!temp.eof())
    {
        temp.getline(fn, 25, '|');
        temp.getline(ln, 25, '|');
        temp.getline(un, 25, '|');
        temp.getline(pd, 25, '|');
        temp.getline(an, 25, '|');
        temp.getline(bl, 25, '|');
        temp.getline(em, 40);
        account << fn << '|' << ln << '|' << un << '|' << pd << '|' << an << '|' << bl << '|' << em << '\n';
    }
    temp.close();
    account.close();
    remove("temp.txt");
    if (mod == 0)
    {
        cout << "\nAccount not found !!\n";
    }
    else if (mod == 1)
    {
        cout << "\nDone!\n\nYou Will Return To Admin Menu Page.\n";
    }
    system("pause");
    system("cls");
    Admin_Menu();
}

void Close_An_Account()
{
    fstream account;
    fstream temp;
    account.open("account.txt", ios::in);
    temp.open("temp.txt", ios::out);
    cin.ignore();
    cout << "\nEnter the Account Number to close it: ";
    cin.getline(acn, 25);
    if (strcmp("", acn) == 0 || !account)
    {
        cout << "\nNo Account Number Entered\n";
        cout << "\nYou Will Return To Admin Menu Page.\n";
        system("pause");
        system("cls");
        Admin_Menu();
    }
    int del = 0;
    while (!account.eof())
    {
        account.getline(fn, 25, '|');
        account.getline(ln, 25, '|');
        account.getline(un, 25, '|');
        account.getline(pd, 25, '|');
        account.getline(an, 25, '|');
        account.getline(bl, 25, '|');
        account.getline(em, 40);
        if (strcmp(acn, an) == 0)
        {
            del = 1;
            continue;
            remove("|");
        }
        else
        {
            temp << fn << '|' << ln << '|' << un << '|' << pd << '|' << an << '|' << bl << '|' << em << '\n';
        }
    }
    temp.close();
    account.close();
    account.open("account.txt", ios::out);
    temp.open("temp.txt", ios::in);
    while (!temp.eof())
    {
        temp.getline(fn, 25, '|');
        temp.getline(ln, 25, '|');
        temp.getline(un, 25, '|');
        temp.getline(pd, 25, '|');
        temp.getline(an, 25, '|');
        temp.getline(bl, 25, '|');
        temp.getline(em, 40);
        account << fn << '|' << ln << '|' << un << '|' << pd << '|' << an << '|' << bl << '|' << em << '\n';
    }
    temp.close();
    account.close();
    remove("temp.txt");
    if (del == 0)
    {
        cout << "\nAccount not found !!\n";
    }
    else if (del == 1)
    {
        cout << "\nDone!\n\nYou Will Return To Admin Menu Page.\n";
    }
    system("pause");
    system("cls");
    Admin_Menu();
}

void List_All_Accounts()
{
    fstream account;
    account.open("account.txt", ios::in);
    if (!account)
    {
        cout << "No Accounts Created\n";
        cout << "\nYou Will Return To Admin Menu Page.\n";
        system("pause");
        system("cls");
        Admin_Menu();
    }
    else
    {
        cout << "\n" << setw(25) << left << "First Name" << setw(25) << left << "Last Name" << setw(25) << left << "User Name" << setw(25) << left << "Password" << setw(25) << left << "Account Number" << setw(25) << left << "Balance" << setw(40) << left << "E-mail" << "\n";
        while (!account.eof())
        {
            account.getline(fn, 25, '|');
            account.getline(ln, 25, '|');
            account.getline(un, 25, '|');
            account.getline(pd, 25, '|');
            account.getline(an, 25, '|');
            account.getline(bl, 25, '|');
            account.getline(em, 40);
            cout << "\n" << setw(25) << left << fn << setw(25) << left << ln << setw(25) << left << un << setw(25) << left << pd << setw(25) << left << an << setw(25) << left << bl << setw(40) << left << em << endl;
        }
        cout << "\nYou Will Return To Admin Menu Page.\n";
        account.close();
        system("pause");
        system("cls");
        Admin_Menu();
    }
}

void User_Menu()
{
    int usr_choice;
    system("cls");
    cout << "Hi User.\n\n";
    cout << "Please choose a number from 1 to 5.\n" << endl;
    cout << "1. Balance Enquiry\n" << "2. Withdraw Amount\n" << "3. Deposit Amount\n" << "4. Transfer Amount\n" << "5. Log Out\n" << endl;
choice:
    cout << "Choice: ";
    cin >> usr_choice;
    switch (usr_choice)
    {
    case 1:
        system("cls");
        cout << "Balance Enquiry\n\n";
        Balance_Enquiry();
        break;
    case 2:
        system("cls");
        cout << "Withdraw\n\n";
        Withdraw_Amount();
        break;
    case 3:
        system("cls");
        cout << "Deposit\n\n";
        Deposit_Amount();
        break;
    case 4:
        system("cls");
        cout << "Transfer\n\n";
        Transfer_Amount();
    case 5:
        cout << "\nYou have logged out from your account.\n";
        system("pause");
        system("cls");
        Welcome();
        break;
    default:
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "\nIncorrect Number.\n";
        cout << "Please type 1, 2, 3, 4, 5 ONLY.\n";
        goto choice;
    }
}

void Balance_Enquiry()
{
    char new_user[25];
    for (int i = 0; i < 25; i++)
    {
        new_user[i] = user[i];
    }
    fstream account;
    account.open("account.txt", ios::in);
    cin.ignore();
    while (!account.eof())
    {
        account.getline(fn, 25, '|');
        account.getline(ln, 25, '|');
        account.getline(un, 25, '|');
        account.getline(pd, 25, '|');
        account.getline(an, 25, '|');
        account.getline(bl, 25, '|');
        account.getline(em, 40);

        if (strcmp(new_user, un) == 0)
        {
            break;
        }
    }
    account.close();
    cout << "Your Balance is: $" << bl << "\n\n";
    cout << "You Will Return To Client Menu Page.\n";
    system("pause");
    system("cls");
    User_Menu();
}

void Withdraw_Amount()
{
    int Length, conv, wd_amount;
    long long balance = 0;
    bool pop = true;
    char sh[25];
    Length = strlen(bl);
    char newbal[25] = { 0 };
    for (int i = 0; i < Length; i++)
    {
        conv = bl[i] - 48;
        balance = (balance * 10) + conv;
    }
    cout << "Enter the Amount: $";
    while (pop)
    {
        cin >> wd_amount;
        if (balance < wd_amount)
        {
            cout << "\n\nNo Enough Balance.\n";
            system("pause");
            system("cls");
            cout << "New Withdraw\n\n";
            cout << "Your balance is : $" << bl;
            cout << "\n\nPlease Enter a New Amount to Withdraw: $";
        }
        else
        {
            balance -= wd_amount;
            pop = false;
        }
    }
    for (int i = Length - 1; i >= 0; i--)
    {
        conv = (balance % 10) + 48;
        balance /= 10;
        newbal[i] = conv;
    }
    for (int i = 0; i < 25; i++)
    {
        sh[i] = user[i];
    }

    fstream account;
    fstream temp;
    account.open("account.txt", ios::in);
    temp.open("temp.txt", ios::out);
    cin.ignore();
    while (!account.eof())
    {
        account.getline(fn, 25, '|');
        account.getline(ln, 25, '|');
        account.getline(un, 25, '|');
        account.getline(pd, 25, '|');
        account.getline(an, 25, '|');
        account.getline(bl, 25, '|');
        account.getline(em, 40);

        if (strcmp(sh, un) == 0)
        {

            temp << fn << '|' << ln << '|' << un << '|' << pd << '|' << an << '|' << newbal << '|' << em << '\n';
        }
        else
            temp << fn << '|' << ln << '|' << un << '|' << pd << '|' << an << '|' << bl << '|' << em << '\n';
    }
    temp.close();
    account.close();
    account.open("account.txt", ios::out);
    temp.open("temp.txt", ios::in);
    while (!temp.eof())
    {
        temp.getline(fn, 25, '|');
        temp.getline(ln, 25, '|');
        temp.getline(un, 25, '|');
        temp.getline(pd, 25, '|');
        temp.getline(an, 25, '|');
        temp.getline(bl, 25, '|');
        temp.getline(em, 40);
        account << fn << '|' << ln << '|' << un << '|' << pd << '|' << an << '|' << bl << '|' << em << '\n';
    }
    temp.close();
    account.close();
    remove("temp.txt");
    cout << "\nWithdraw Successful!" << endl;
    cout << "Current Balance: $" << newbal << endl;
    cout << "\nYou Will Return To User Menu Page.\n";
    system("pause");
    system("cls");
    User_Menu();
}

void Deposit_Amount()
{
    int Length, conv, dpamount;
    long long balance = 0;
    char sh[25];
    Length = strlen(bl);
    char newbal[25] = { 0 };
    for (int i = 0; i < Length; i++)
    {
        conv = bl[i] - 48;
        balance = (balance * 10) + conv;
    }
    cout << "Enter the Amount: $";
    cin >> dpamount;
    balance += dpamount;

    for (int i = Length - 1; i >= 0; i--)
    {
        conv = (balance % 10) + 48;
        balance /= 10;
        newbal[i] = conv;
    }
    for (int i = 0; i < 25; i++)
    {
        sh[i] = user[i];
    }

    fstream account;
    fstream temp;
    account.open("account.txt", ios::in);
    temp.open("temp.txt", ios::out);
    cin.ignore();
    while (!account.eof())
    {
        account.getline(fn, 25, '|');
        account.getline(ln, 25, '|');
        account.getline(un, 25, '|');
        account.getline(pd, 25, '|');
        account.getline(an, 25, '|');
        account.getline(bl, 25, '|');
        account.getline(em, 40);

        if (strcmp(sh, un) == 0)
        {

            temp << fn << '|' << ln << '|' << un << '|' << pd << '|' << an << '|' << newbal << '|' << em << '\n';
        }
        else
            temp << fn << '|' << ln << '|' << un << '|' << pd << '|' << an << '|' << bl << '|' << em << '\n';
    }
    temp.close();
    account.close();
    account.open("account.txt", ios::out);
    temp.open("temp.txt", ios::in);
    while (!temp.eof())
    {
        temp.getline(fn, 25, '|');
        temp.getline(ln, 25, '|');
        temp.getline(un, 25, '|');
        temp.getline(pd, 25, '|');
        temp.getline(an, 25, '|');
        temp.getline(bl, 25, '|');
        temp.getline(em, 40);
        account << fn << '|' << ln << '|' << un << '|' << pd << '|' << an << '|' << bl << '|' << em << '\n';
    }
    temp.close();
    account.close();
    remove("temp.txt");
    cout << "\nDeposit Successful!" << endl;
    cout << "Current Balance: $" << newbal << endl;
    cout << "\nYou Will Return To User Menu Page.\n";
    system("pause");
    system("cls");
    User_Menu();
}

void Transfer_Amount()
{
    int Length1, Length2, conv1, conv2, ts_amount;
    long long balance1 = 0, balance2 = 0;
    bool pop1 = true;
    char sh[25];
    Length1 = strlen(bl);
    char newbal1[25] = { 0 }, newbal2[25] = { 0 };
    fstream account;
    fstream temp;
    for (int i = 0; i < Length1; i++)
    {
        conv1 = bl[i] - 48;
        balance1 = (balance1 * 10) + conv1;
    }
    cout << "Enter the Amount: $";
    while (pop1)
    {
        cin >> ts_amount;
        if (balance1 < ts_amount)
        {
            cout << "\n\nNo Enough Balance.\n";
            system("pause");
            system("cls");
            cout << "New Withdraw\n\n";
            cout << "Your balance is : $" << bl;
            cout << "\n\nPlease Enter a New Amount to Withdraw: $";
        }
        else
        {
            balance1 -= ts_amount;
            pop1 = false;
        }
    }
    cout << " \nEnter Account Number You Want To Transfer To: ";
    cin >> acn;
    if (strcmp("", acn) == 0 || !account)
    {
        cout << "\nNo Account Number Entered\n";
        cout << "\nYou Will Return To User Menu Page.\n";
        system("pause");
        system("cls");
        User_Menu();
    }
    for (int i = Length1 - 1; i >= 0; i--)
    {
        conv1 = (balance1 % 10) + 48;
        balance1 /= 10;
        newbal1[i] = conv1;
    }
    for (int i = 0; i < 25; i++)
    {
        sh[i] = user[i];
    }
    account.open("account.txt", ios::in);
    temp.open("temp.txt", ios::out);
    cin.ignore();
    while (!account.eof())
    {
        account.getline(fn, 25, '|');
        account.getline(ln, 25, '|');
        account.getline(un, 25, '|');
        account.getline(pd, 25, '|');
        account.getline(an, 25, '|');
        account.getline(bl, 25, '|');
        account.getline(em, 40);

        if (strcmp(an, acn) == 0)
        {
            Length2 = strlen(bl);
            for (int i = 0; i < Length2; i++)
            {
                conv2 = bl[i] - 48;
                balance2 = (balance2 * 10) + conv2;
            }
            balance2 += ts_amount;
            for (int i = Length2 - 1; i >= 0; i--)
            {
                conv2 = (balance2 % 10) + 48;
                balance2 /= 10;
                newbal2[i] = conv2;
            }
            temp << fn << '|' << ln << '|' << un << '|' << pd << '|' << an << '|' << newbal2 << '|' << em << '\n';
        }
        else if (strcmp(sh, un) == 0)
        {

            temp << fn << '|' << ln << '|' << un << '|' << pd << '|' << an << '|' << newbal1 << '|' << em << '\n';
        }
        else
            temp << fn << '|' << ln << '|' << un << '|' << pd << '|' << an << '|' << bl << '|' << em << '\n';
    }
    temp.close();
    account.close();
    account.open("account.txt", ios::out);
    temp.open("temp.txt", ios::in);
    while (!temp.eof())
    {
        temp.getline(fn, 25, '|');
        temp.getline(ln, 25, '|');
        temp.getline(un, 25, '|');
        temp.getline(pd, 25, '|');
        temp.getline(an, 25, '|');
        temp.getline(bl, 25, '|');
        temp.getline(em, 40);
        account << fn << '|' << ln << '|' << un << '|' << pd << '|' << an << '|' << bl << '|' << em << '\n';
    }
    temp.close();
    account.close();
    remove("temp.txt");
    cout << "\nTransformation Successful!" << endl;
    cout << "Current Balance: $" << newbal1 << endl;
    cout << "\nYou Will Return To user Menu Page.\n";
    system("pause");
    system("cls");
    User_Menu();
}

// =================================== Done ;) =================================== \\