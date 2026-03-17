#include "Wallet.h"
#include <iostream>

using namespace std;

int main() {
    Wallet w1("kim", 100);
    w1.print();
    w1.withdraw(30);
    w1.print();
    w1.deposit(10);
    w1.print();

    Wallet w2("lee");
    w2.withdraw(50);
    w2.print();

    return 0;
}
