#include <iostream>
#include <string>

using namespace std;

/*
디폴트 매개변수
1) 디폴트 매개변수는 "인수를 생략했을 때 자동으로 채워지는 값"
2) 보통 선언부에 적어야 함수 사용자가 기본값을 한눈에 볼 수 있다.
3) 디폴트 값은 뒤에서부터 연속으로만 줄 수 있다.
->  잘 쓰면 비슷한 함수 여러개를 만들 필요가 없어져 코드가 단순해진다.
*/

void star(int count = 5);
void msg(int id, string text = "");
void calc(int a, int b = 5, int c = 0, int d = 0); // 뒤에서부터 디폴트 값 줄 수 있음
void fillLine(int n = 25, char c = '*');
// void calc(int a, int b = 5, int c, int d = 0); -> 이건 안됨 (중간이 빔)

/*-------------------------------------------------------*/

void star(int count) // star(10), star() 둘다 가능 -> Default값이 있기 때문
{
    cout << "STAR : ";
    for(int i = 0; i < count ; i++)
        cout << "*";
    cout << endl;
}

void msg(int id, string text) // msg(10)으로 호출 가능
{
    cout << "ID : " << id << " TEXT : " << text << endl;
}

void calc(int a, int b, int c, int d) // calc(1), calc(1,2)으로 호출 가능
{
    cout << "CALC : " << a << ", " << b << ", " << c << ", " << d << endl;
}

void fillLine(int n, char c) // fillLine()으로 호출 가능
{
    cout << "FILL_LINE : ";
    for(int i = 0; i < n; i++)
        cout << c;
    cout << endl;
}

/*-------------------------------------------------------*/

int main()
{
    star();
    star(10);
    msg(10);
    msg(10, "Hello");
    calc(1);
    calc(1,2);
    calc(1,2,3);
    calc(1,2,3,4);
    fillLine();
    fillLine(5);
    // fillLine('H'); -> 인자를 n먼저 받아 원하는 대로 출력 x
    fillLine(3, 'H');
}