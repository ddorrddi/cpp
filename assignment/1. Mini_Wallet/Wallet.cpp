#include "Wallet.h"
#include <iostream>

// 기본 생성자
Wallet::Wallet() : owner("none"), balance(0), lastTx({"", 0}) {
    std::cout << "--------Wallet Created (owner: none, balance: 0)--------\n";
}

// 매개변수 생성자
Wallet::Wallet(const std::string& owner, int balance)
    : owner(owner), balance(balance < 0 ? 0 : balance), lastTx({"", 0})
{
    if (balance < 0) {
        std::cout << "invalid balance\n";
    }
    std::cout << "--------Wallet Created (owner: " << owner
              << ", balance: " << this->balance << ")--------\n";
}

// 위임 생성자: balance = 0으로 위임
Wallet::Wallet(const std::string& owner) : Wallet(owner, 0)
{
    std::cout << "--------Wallet Created With Default Balance (owner: " << owner
              << ", balance: 0)--------\n";
}

Wallet::~Wallet() {
    std::cout << "bye " << owner << "\n";
}

void Wallet::deposit(int amount) {
    if (amount <= 0) return;
    balance += amount;
    lastTx = {"deposit", amount};
}

bool Wallet::withdraw(int amount) {
    if (amount > balance) {
        std::cout << "REQUEST FAIL : (REQUEST " << amount
                  << ", AMOUNT " << balance << ")\n" << "--------\n";
        return false;
    }
    balance -= amount;
    lastTx = {"withdraw", amount};
    return true;
}

void Wallet::print() const {
    if(lastTx.type.empty()){
        std::cout << "owner: " << owner
                  << ", balance: " << balance
                  << ", lastTx: [none]\n" << "--------\n";
        return;
    }
    else{
        std::cout << "owner: " << owner
                  << ", balance: " << balance
                  << ", lastTx: [" << lastTx.type << " " << lastTx.amount << "]\n" << "--------\n";
    }
}
