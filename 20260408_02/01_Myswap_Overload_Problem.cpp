#include <iostream>

using namespace std;

/*
중복  함수의 문제 : 타입만 다르고 내용을 동일
myswap(int& , int&)와 myswap(double& , double&)는 코드는 같고 타입만 다름
*/

void myswap(int& a, int& b){
    int tmp = a; a = b; b = tmp;
}

void myswap(double& a, double& b){
    double tmp = a; a = b; b = tmp;
}

int main()
{
    int a = 1, b = 2;
    myswap(a, b);
    cout << a << " " << b << endl;

    double c = 0.4, d = 12.6;
    myswap(c, d);
    cout << c << " " << d << endl;

    return 0;
}