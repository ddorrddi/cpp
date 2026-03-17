#pragma once
#include <string>

struct Transaction {
    std::string type;   // "deposit" or "withdraw"
    int amount;
};

class Wallet {
private:
    std::string owner;
    int balance;
    Transaction lastTx;

public:
    // 기본 생성자
    Wallet();
    // 매개변수 생성자 (owner + balance)
    Wallet(const std::string& owner, int balance);
    // 위임 생성자 (owner만, balance = 0)
    Wallet(const std::string& owner);

    ~Wallet();

    void deposit(int amount);
    bool withdraw(int amount);
    void print() const;

    inline int getBalance() const { return balance; }
};
