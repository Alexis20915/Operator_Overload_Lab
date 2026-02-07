#ifndef BANKACCOUNT_H  // Stops this file from being included twice
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    // These are pointers - they point to memory where data is stored
    std::string* accountNumber;     // Points to account number
    std::string* accountHolderName; // Points to holder name
    double balance;                 // The money in the account

public:
    // These make new accounts
    BankAccount();  // Makes empty account
    BankAccount(const std::string& num, const std::string& name, double bal); // Makes account with info

    // These three are needed because we use pointers
    BankAccount(const BankAccount& other);            // Makes a copy
    BankAccount& operator=(const BankAccount& other); // Copies one to another
    ~BankAccount();                                   // Cleans up

    // These get information
    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;
    double getBalance() const;

    // These change information
    void setAccountNumber(const std::string& num);
    void setAccountHolderName(const std::string& name);
    void setBalance(double bal);

    // These do bank stuff
    bool deposit(double amount);
    bool withdraw(double amount);

    // These let us use + and - with accounts
    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);

    // These let us compare accounts
    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;

    // These work without having an account object
    static void printAccount(const BankAccount& account);
    static BankAccount createAccountFromInput();
};

#endif