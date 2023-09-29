#include "Menu.h"
#include <iostream>

using namespace std;

void Menu::Run() {
    while (true) {
        DisplayMenu();
        int choice;
        cin >> choice;
        HandleChoice(choice);
    }
}
void Menu::DisplayMenu() const {
    cout << "\nPersonal Finance Manager Menu:" << endl;
    cout << "1. Add Wallet" << endl;
    cout << "2. Add Card" << endl;
    cout << "3. Make a Withdrawal" << endl;
    cout << "4. Make a Deposit" << endl;
    cout << "5. Check Balance" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

void Menu::HandleChoice(int choice) {
    switch (choice) {
    case 1:
        AddWallet();
        break;
    case 2:
        AddCard();
        break;
    case 3:
        MakeWithdrawal();
        break;
    case 4:
        MakeDeposit();
        break;
    case 5:
        CheckBalance();
        break;
    case 6:
        exit(0);
    default:
        cout << "\nInvalid choice. Please try again." << endl;
        break;
    }
}

void Menu::AddWallet() {

    string walletName;
    cout << "\nEnter wallet name: ";
    cin >> walletName;

    manager.AddWallet(walletName);
}

void Menu::AddCard() {

    string cardName;
    double creditLimit;

    cout << "\nEnter card name: ";
    cin >> cardName;
    cout << "Enter credit limit: ";
    cin >> creditLimit;

    manager.AddCard(cardName, creditLimit);
}

void Menu::MakeWithdrawal() {
    string name;
    double amount;
    string category;
    int day;
    int month;
    int year;

    cout << "\nEnter wallet/card name: ";
    cin >> name;

    Wallet* wallet = manager.GetWallet(name);
    Card* card = manager.GetCard(name);

    if (wallet || card) {

        cout << "Enter withdrawal amount: ";
        cin >> amount;

        do {
            cout << "Enter category (Food, Rent, or Entertainment): ";
            cin >> category;

        } while (category != "Food" && category 
            != "Rent" && category != "Entertainment");

        cout << "Enter day: ";
        cin >> day; 
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;


        if (wallet) {
            wallet->Withdraw(amount);
        }
        else {
            card->MakePurchase(amount);
        }
    }
    else {
        cout << "\nWallet/Card not found." << endl;
    }
}

void Menu::MakeDeposit() {
    string name;
    double amount;

    cout << "\nEnter wallet/card name: ";
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
        cout << "\nWallet/Card not found." << endl;
    }
}

void Menu::CheckBalance() {
    string name;
    cout << "\nEnter wallet/card name: ";
    cin >> name;
    Wallet* wallet = manager.GetWallet(name);
    Card* card = manager.GetCard(name);
    if (wallet || card) {
        double balance = wallet ? wallet->GetBalance() : card->CheckBalance();
        cout << "\nBalance for " << name << ": " << balance << endl;
    }
    else {
        cout << "\nWallet/Card not found." << endl;
    }
}