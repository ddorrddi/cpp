#include <iostream>
#include "11_Class_File_Sep_Circle.h"

using namespace std;

int main()
{
    Circle donut;
    Circle pizza(10);

    cout << "Donut Area = " << donut.getArea() << endl;
    cout << "Pizza Area = " << pizza.getArea() << endl;
}