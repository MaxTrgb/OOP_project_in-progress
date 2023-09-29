#pragma once

#include "PersonalFinanceManager.h"

class Menu {
private:
    PersonalFinanceManager manager;

public:
    void Run();

private:
    void DisplayMenu() const;
    void HandleChoice(int choice);
    void AddWallet();
    void AddCard();
    void MakeWithdrawal();
    void MakeDeposit();
    void CheckBalance();
};
