#include <iostream>

using namespace std;

/*
T Bigger(T a, T b) : 비교 연산 (>)이 가능한 타입만 사용 가능
*/

template <class T>

T Bigger(T a, T b){
    return ( a > b ) ? a : b;
}

int main()
{
    int a = 20, b = 50;
    char c = 'a', d = 'z';

    cout << Bigger(a, b) << endl;
    cout << Bigger(c, d) << endl;

    return 0;
}