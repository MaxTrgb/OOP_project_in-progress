#include <iostream>
#include "PersonalFinanceManager.h"
using namespace std;

int main() {
    PersonalFinanceManager manager;

    while (true) {
        cout << "Personal Finance Manager Menu:" << endl;
        cout << "1. Add Wallet" << endl;
        cout << "2. Add Card" << endl;
        cout << "3. Make a Withdrawal" << endl;
        cout << "4. Make a Deposit" << endl; // Added option for deposit
        cout << "5. Check Balance" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
        {
            string walletName;
            cout << "Enter wallet name: ";
            cin >> walletName;
            manager.AddWallet(walletName);
        }
        break;
        case 2:
        {
            string cardName;
            double creditLimit;
            cout << "Enter card name: ";
            cin >> cardName;
            cout << "Enter credit limit: ";
            cin >> creditLimit;
            manager.AddCard(cardName, creditLimit);
        }
        break;
        case 3:
        {
            string name;
            double amount;
            cout << "Enter wallet/card name: ";
            cin >> name;
            Wallet* wallet = manager.GetWallet(name);
            Card* card = manager.GetCard(name);
            if (wallet || card) {
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                if (wallet)
                    wallet->Withdraw(amount);
                else
                    card->MakePurchase(amount);
            }
            else {
                cout << "Wallet/Card not found." << endl;
            }
        }
        break;
        case 4:
        {
            string name;
            double amount;
            cout << "Enter wallet/card name: ";
            cin >> name;
            Wallet* wallet = manager.GetWallet(name);
            Card* card = manager.GetCard(name);
            if (wallet || card) {
                cout << "Enter deposit amount: ";
                cin >> amount;
                if (wallet)
                    wallet->Deposit(amount);
                else
                    card->Deposit(amount);
            }
            else {
                cout << "Wallet/Card not found." << endl;
            }
        }
        break;
        case 5:
        {
            string name;
            cout << "Enter wallet/card name: ";
            cin >> name;
            Wallet* wallet = manager.GetWallet(name);
            Card* card = manager.GetCard(name);
            if (wallet || card) {
                double balance = wallet ? wallet->GetBalance() : card->CheckBalance();
                cout << "Balance for " << name << ": " << balance << endl;
            }
            else {
                cout << "Wallet/Card not found." << endl;
            }
        }
        break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}
