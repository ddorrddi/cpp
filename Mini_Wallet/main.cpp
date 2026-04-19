#include "Mini_Wallet.h"

int main()
{
    Wallet w1("LEE", 100);
    w1.withdraw(30);
    w1.deposit(10);
    w1.print();
    Wallet w2("HOHWI");
    w2.withdraw(50);
    w2.print();
}