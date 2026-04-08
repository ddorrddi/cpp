#include <iostream>

using namespace std;

// 생성자를 아무것도 만들지 않으면 컴파일러가 기본생성자를 만들어줌
class A{
public:
    int x;
};

// 이경우에는 매개변수 생성자가 있기 때문에 main에서 B b; 컴파일 에러
class B{
public:
    int x;
    B(int v) { x = v; }
};

int main()
{
    A a;
    cout << "A ok" << endl;
    cout << a.x << endl;

    B b(10);
    cout << "B ok" << endl;
}