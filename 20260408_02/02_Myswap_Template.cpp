#include <iostream>

using namespace std;

/*
템플릿 함수 myswap<T>
- template <class T>
- 호출할 때 컴파일라 T가 결정하고 해당 타입 버전 함수를 생성
*/

template <class T>

void myswap(T& a, T& b){
    T tmp = a; a = b; b = tmp;
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