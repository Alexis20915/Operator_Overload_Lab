// Alexis Lopez Echevarria, 6 February 2026,  Program is a updated bank model, allowing multi bank accounts with adding and removing money
// AI ASSISTANCE DISCLOSURE
//
// Tool(s) Used: [ChatGPT, DeepSeek]
// Date(s) of Use: [2/6/26]
//
// Description of Use:
// [Briefly (1-3 sentences) describe how you used the tool(s). Be specific.]
// AI was used to help me solve some errors in my code, mostly syntax or a variety of misspelled words that wasnt showing up as an erorr,
// along with some : that were supposed to be ;, and to debloat some parts of the code
// While DeepSeek was used more so on explaining parts i forgot about or how to do, explaining it in a way i can try and remember.

#include "BankAccount.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Finds account by number
int findAccount(const vector<BankAccount>& accounts, const string& num) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == num) {
            return i; // Found it
        }
    }
    return -1; // Not found
}

int main() {
    vector<BankAccount> accounts; // All accounts
    int choice;
    bool running = true;

    while (running) {
        // Show menu
        cout << endl;
        cout << "===== Bank Menu =====" << endl;
        cout << "1. Make account (new way)" << endl;
        cout << "2. See all accounts" << endl;
        cout << "3. Put money in (normal)" << endl;
        cout << "4. Take money out (normal)" << endl;
        cout << "5. Change name" << endl;
        cout << "6. Put money in (+=)" << endl;
        cout << "7. Take money out (-=)" << endl;
        cout << "8. Compare accounts" << endl;
        cout << "9. Show copy" << endl;
        cout << "10. Show assignment" << endl;
        cout << "11. Print account (new way)" << endl;
        cout << "12. Quit" << endl;
        cout << "Pick: ";
        cin >> choice;
        cin.ignore(); // Clear input

        if (choice == 1) {
            // New way to make account
            BankAccount newAcc = BankAccount::createAccountFromInput();
            accounts.push_back(newAcc);
        }

        else if (choice == 2) {
            if (accounts.empty()) {
                cout << "No accounts." << endl;
            } else {
                for (int i = 0; i < accounts.size(); i++) {
                    cout << endl << "Account " << i + 1 << endl;
                    // New way to print
                    BankAccount::printAccount(accounts[i]);
                }
            }
        }

        else if (choice == 6) {
            // Using +=
            string num;
            double amount;

            cout << "Account number: ";
            getline(cin, num);

            int pos = findAccount(accounts, num);
            if (pos == -1) {
                cout << "No account." << endl;
            } else {
                cout << "How much to add? $";
                cin >> amount;
                cin.ignore();

                accounts[pos] += amount; // Use +=
            }
        }

        else if (choice == 7) {
            // Using -=
            string num;
            double amount;

            cout << "Account number: ";
            getline(cin, num);

            int pos = findAccount(accounts, num);
            if (pos == -1) {
                cout << "No account." << endl;
            } else {
                cout << "How much to take? $";
                cin >> amount;
                cin.ignore();

                accounts[pos] -= amount; // Use -=
            }
        }

        else if (choice == 8) {
            // Compare accounts
            if (accounts.size() < 2) {
                cout << "Need 2 accounts." << endl;
            } else {
                string num1, num2;

                cout << "First account number: ";
                getline(cin, num1);

                cout << "Second account number: ";
                getline(cin, num2);

                int pos1 = findAccount(accounts, num1);
                int pos2 = findAccount(accounts, num2);

                if (pos1 == -1 || pos2 == -1) {
                    cout << "One or both not found." << endl;
                } else {
                    cout << "\nComparing:" << endl;

                    // Use ==
                    if (accounts[pos1] == accounts[pos2]) {
                        cout << "Same account number." << endl;
                    } else {
                        cout << "Different account numbers." << endl;
                    }

                    // Use < and >
                    if (accounts[pos1] < accounts[pos2]) {
                        cout << "First has less money." << endl;
                    } else if (accounts[pos1] > accounts[pos2]) {
                        cout << "First has more money." << endl;
                    } else {
                        cout << "Same money." << endl;
                    }
                }
            }
        }

        else if (choice == 9) {
            // Show copy constructor
            if (accounts.empty()) {
                cout << "No accounts." << endl;
            } else {
                int idx;
                cout << "Which account to copy? ";
                cin >> idx;
                cin.ignore();

                if (idx >= 0 && idx < accounts.size()) {
                    // Make copy
                    BankAccount copy = accounts[idx];

                    cout << "\nOriginal:" << endl;
                    BankAccount::printAccount(accounts[idx]);

                    cout << "Copy:" << endl;
                    BankAccount::printAccount(copy);

                    // Change copy to show it's different
                    copy.setAccountHolderName("Copy of " + copy.getAccountHolderName());
                    cout << "After changing copy:" << endl;
                    BankAccount::printAccount(copy);
                } else {
                    cout << "Bad number." << endl;
                }
            }
        }

        else if (choice == 10) {
            // Show assignment
            if (accounts.size() < 2) {
                cout << "Need 2 accounts." << endl;
            } else {
                cout << "Before:" << endl;
                cout << "Account 0: " << accounts[0].getAccountHolderName()
                     << ", $" << accounts[0].getBalance() << endl;
                cout << "Account 1: " << accounts[1].getAccountHolderName()
                     << ", $" << accounts[1].getBalance() << endl;

                // Copy one to another
                accounts[0] = accounts[1];

                cout << "\nAfter (account0 = account1):" << endl;
                cout << "Account 0: " << accounts[0].getAccountHolderName()
                     << ", $" << accounts[0].getBalance() << endl;
                cout << "Account 1: " << accounts[1].getAccountHolderName()
                     << ", $" << accounts[1].getBalance() << endl;
            }
        }

        else if (choice == 12) {
            cout << "Bye!" << endl;
            running = false;
        }

        else {
            cout << "Bad choice." << endl;
        }
    }

    return 0;
}