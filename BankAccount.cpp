#include "BankAccount.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// Makes empty account
BankAccount::BankAccount() {
    accountNumber = new string("");      // Make space for number
    accountHolderName = new string("");  // Make space for name
    balance = 0.0;                       // Start with no money
}

// Makes account with info
BankAccount::BankAccount(const string& num, const string& name, double bal) {
    accountNumber = new string(num);      // Store number
    accountHolderName = new string(name); // Store name

    // Don't allow negative balance
    if (bal >= 0) {
        balance = bal;
    } else {
        balance = 0.0;
    }
}

// Makes a copy of an account
BankAccount::BankAccount(const BankAccount& other) {
    // Make new memory for the copy
    accountNumber = new string(*(other.accountNumber));
    accountHolderName = new string(*(other.accountHolderName));
    balance = other.balance;
}

// Copies one account to another
BankAccount& BankAccount::operator=(const BankAccount& other) {
    // Don't copy to yourself
    if (this != &other) {
        // Delete old memory
        delete accountNumber;
        delete accountHolderName;

        // Make new memory and copy
        accountNumber = new string(*(other.accountNumber));
        accountHolderName = new string(*(other.accountHolderName));
        balance = other.balance;
    }
    return *this;
}

// Cleans up when account is deleted
BankAccount::~BankAccount() {
    delete accountNumber;
    delete accountHolderName;
}

// Gets account number
string BankAccount::getAccountNumber() const {
    return *accountNumber;
}

// Gets holder name
string BankAccount::getAccountHolderName() const {
    return *accountHolderName;
}

// Gets balance
double BankAccount::getBalance() const {
    return balance;
}

// Changes account number
void BankAccount::setAccountNumber(const string& num) {
    *accountNumber = num;
}

// Changes holder name
void BankAccount::setAccountHolderName(const string& name) {
    *accountHolderName = name;
}

// Changes balance
void BankAccount::setBalance(double bal) {
    if (bal >= 0) {
        balance = bal;
    }
}

// Puts money in account
bool BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        return true;
    }
    return false;
}

// Takes money from account
bool BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

// Uses += to add money
BankAccount& BankAccount::operator+=(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Added $" << fixed << setprecision(2) << amount << endl;
    } else {
        cout << "Can't add negative money" << endl;
    }
    return *this;
}

// Uses -= to take money
BankAccount& BankAccount::operator-=(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Took out $" << fixed << setprecision(2) << amount << endl;
    } else {
        cout << "Can't take out that much" << endl;
    }
    return *this;
}

// Checks if accounts have same number
bool BankAccount::operator==(const BankAccount& other) const {
    return *accountNumber == *(other.accountNumber);
}

// Checks if this account has less money
bool BankAccount::operator<(const BankAccount& other) const {
    return balance < other.balance;
}

// Checks if this account has more money
bool BankAccount::operator>(const BankAccount& other) const {
    return balance > other.balance;
}

// Prints account info (no account object needed)
void BankAccount::printAccount(const BankAccount& account) {
    cout << "\n=== Account Info ===" << endl;
    cout << "Number: " << account.getAccountNumber() << endl;
    cout << "Name: " << account.getAccountHolderName() << endl;
    cout << "Balance: $" << fixed << setprecision(2) << account.getBalance() << endl;
    cout << "====================" << endl;
}

// Makes new account from user input (no account object needed)
BankAccount BankAccount::createAccountFromInput() {
    string num, name;
    double bal;

    cout << "\n=== Make New Account ===" << endl;

    cout << "Account number: ";
    getline(cin, num);

    cout << "Account holder name: ";
    getline(cin, name);

    cout << "Starting balance: $";
    cin >> bal;
    cin.ignore();

    // Keep asking if balance is negative
    while (bal < 0) {
        cout << "Balance can't be negative. Try again: $";
        cin >> bal;
        cin.ignore();
    }

    cout << "Account made!" << endl;

    // Return the new account
    return BankAccount(num, name, bal);
}