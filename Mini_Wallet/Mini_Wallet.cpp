#include "Mini_Wallet.h"

Wallet::Wallet() : owner("none"), balance(0), lastTX({"", 0}) {}

Wallet::Wallet(string owner, int balance) : owner(owner), balance(balance > 0 ? balance : 0), lastTX({"", 0})
{
    if(balance < 0)
        cout << "invalid balance";
}

Wallet::Wallet(string owner) : Wallet(owner, 0) {}

Wallet::~Wallet() { cout << "Bye " << owner << endl; }

void Wallet::deposit(int amount)
{
    if(amount <= 0)
        return;
    balance += amount;
    lastTX = {"DEPOSIT", amount};
}

bool Wallet::withdraw(int amount)
{
    if(amount >= balance){
        cout << "Withdraw Fail" << endl;
        lastTX = {"WITHDRAW", amount};
        return false;
    }
    balance -= amount;
    lastTX = {"WITHDRAW", amount};
    return true;
}

void Wallet::print()
{
    cout << "OWNER : " << owner << " / BALANCE : " << balance << " / LAST TX : " << lastTX.type << " " << lastTX.amount << endl;
}