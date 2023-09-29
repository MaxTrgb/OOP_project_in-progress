#pragma once
#include <string>
using namespace std;

class Card {
private:
    string cardName;
    double cardBalance;
    double creditLimit;

public:
    Card(): cardName(""), cardBalance(0.0), creditLimit(0.0){}
    Card(const string& cardName, double cardBalance, double creditLimit);
    void Deposit(double amount);
    void MakePurchase(double amount);
    double CheckBalance() const;
    string GetName() const;

};
