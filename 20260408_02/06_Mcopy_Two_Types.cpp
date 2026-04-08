#include <iostream>

using namespace std;

/*
mcopy<T1, T2> : 서로 다른 타입 배열 복사
- 템플릿 타입 2개 사용
    T1 : source  타입, T2 : destination 타입
- dest[i] = (T2)src[i]로 캐스팅
*/

template <class T1, class T2>

void mcopy(T1 src[], T2 destination[], int size){
    for(int i = 0; i < size; i++)
        destination[i] = (T2)src[i];
}

int main()
{
    int x[5] = {1, 2, 3, 4, 5};
    double y[5] = {1.2, 3.4, 5.6, 7.8, 9.0};
    char c[5] = {'h', 'e', 'l', 'l', 'o'};
    char s[5] = {'h', 'o', 'h', 'w', 'i'};

    mcopy(x, y, 5);
    mcopy(c, s, 5);

    for(int i = 0; i < 5; i++)
        cout << y[i] << " ";
    cout << endl;

    for(int i = 0; i < 5; i++)
        cout << s[i] << " ";
    cout << endl;

    return 0;
}