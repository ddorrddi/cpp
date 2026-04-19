#include <iostream>
#include <string>

using namespace std;

#ifndef MINI_WALLET_H
#define MINI_WALLET_H

struct Transaction{
    string type;
    int amount;
};

class Wallet{
private:
    string owner;
    int balance;
    Transaction lastTX;
public:
    Wallet();
    Wallet(string owner, int balance);
    Wallet(string owner);
    ~Wallet();
    void deposit(int amount);
    bool withdraw(int amount);
    void print();

    inline int getBalance() const { return balance; }
};

#endif