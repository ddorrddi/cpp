#include <iostream>

using namespace std;

/*
기본 클래스에 기본 생성자 없는 경우
 - 파생 클래스 생성자는 기본적으로 Base()를 호출
 - 그런데 Base()없고, Base(int)만 있다면, 파생클래스에서 어떤 Base가 생성자를 호출할 지 명시해야함
*/

class A{
public:
    A(int x) { cout << "Ctor A(int) " << x << endl; }
};

class B : public A{
public:
    B() : A(10) { cout << "Ctor B " << endl; }
    B(int x) : A(x + 3) { cout << "[Ctor] B(int)" << endl;}
};

int main(){
    B b1;
    B b2(3);
    return 0;
}