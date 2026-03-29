#include <iostream>
#include "12_Mini_Project_Adder.h"
#include "12_Mini_Project_Calculator.h"

using namespace std;

void CALCULATOR::run()
{
    cout << "Insert Two Integers : ";
    int a, b;
    cin >> a >> b;
    Adder adder(a, b);
    cout << adder.process() << endl;
}