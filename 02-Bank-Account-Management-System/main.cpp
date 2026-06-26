#include <iostream>
#include <fstream>
using namespace std;

class Account {
    int accNo;
    char name[50];
    float balance;

public:
    void create() {
        cout << "\nEnter Account No: ";
        cin >> accNo;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void display() const {
        cout << "\nAccount No: " << accNo;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }

    int getAccNo() const {
        return accNo;
    }

    void deposit(float amt) {
        balance += amt;
    }

    bool withdraw(float amt) {
        if (amt > balance) return false;
        balance -= amt;
        return true;
    }
};

// file path
const char* FILE_NAME = "data/bank.dat";

// create account
void createAccount() {
    Account a;
    ofstream file(FILE_NAME, ios::binary | ios::app);

    a.create();
    file.write((char*)&a, sizeof(a));

    cout << "\nAccount Created Successfully!\n";
}

// display all
void displayAll() {
    Account a;
    ifstream file(FILE_NAME, ios::binary);

    while (file.read((char*)&a, sizeof(a))) {
        a.display();
        cout << "\n----------------------";
    }
}

// deposit
void depositMoney() {
    int acc;
    float amt;
    Account a;
    fstream file(FILE_NAME, ios::binary | ios::in | ios::out);

    cout << "\nEnter Account No: ";
    cin >> acc;

    while (file.read((char*)&a, sizeof(a))) {
        if (a.getAccNo() == acc) {
            cout << "Enter Amount: ";
            cin >> amt;

            a.deposit(amt);

            file.seekp(-sizeof(a), ios::cur);
            file.write((char*)&a, sizeof(a));

            cout << "\nDeposit Successful!";
            return;
        }
    }
    cout << "\nAccount Not Found!";
}

// withdraw
void withdrawMoney() {
    int acc;
    float amt;
    Account a;
    fstream file(FILE_NAME, ios::binary | ios::in | ios::out);

    cout << "\nEnter Account No: ";
    cin >> acc;

    while (file.read((char*)&a, sizeof(a))) {
        if (a.getAccNo() == acc) {
            cout << "Enter Amount: ";
            cin >> amt;

            if (a.withdraw(amt)) {
                file.seekp(-sizeof(a), ios::cur);
                file.write((char*)&a, sizeof(a));
                cout << "\nWithdrawal Successful!";
            } else {
                cout << "\nInsufficient Balance!";
            }
            return;
        }
    }
    cout << "\nAccount Not Found!";
}

// check balance
void checkBalance() {
    int acc;
    Account a;
    ifstream file(FILE_NAME, ios::binary);

    cout << "\nEnter Account No: ";
    cin >> acc;

    while (file.read((char*)&a, sizeof(a))) {
        if (a.getAccNo() == acc) {
            a.display();
            return;
        }
    }
    cout << "\nAccount Not Found!";
}

// main menu
int main() {
    int choice;

    do {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Display All\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Check Balance\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: displayAll(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: checkBalance(); break;
            case 6: cout << "\nExiting...\n"; break;
            default: cout << "\nInvalid Choice!";
        }

    } while (choice != 6);

    return 0;
}