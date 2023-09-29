#pragma once
#include <string>
using namespace std;

class Wallet {
private:
    string walletName;
    double balance;

public:
    Wallet() : walletName(""), balance(0.0) {}
    Wallet(const string& walletName, double balance = 0); // Modified constructor declaration
    void Deposit(double amount);
    void Withdraw(double amount);
    double GetBalance() const;
    string GetName() const;
};
