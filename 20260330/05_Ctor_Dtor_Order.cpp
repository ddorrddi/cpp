#include <iostream>

using namespace std;

/*
생성자 / 소멸자 실행 순서
1) 생성 순서 : Base -> Derived ( 부모 먼저 )
2) 소멸 순서 : Derived -> Base ( 자식 먼저 )
이유 : 파생 클래스가 기본 클래스 상태를 기반으로 동작하므로 기본 클래스 부분이 먼저 준비 되어야함
*/

class A{
public:
    A() { cout << "[Ctor] A" << endl; }
    ~A() { cout << "[Dtor] A" << endl;}
};

class B : public A{
public:
    B() { cout << "[Ctor] B" << endl; }
    ~B() { cout << "[Dtor] B" << endl;}
};

class C : public B{
public:
    C() { cout << "[Ctor] C" << endl; }
    ~C() { cout << "[Dtor] C" << endl;}
};

int main()
{
    A a;
    B b;
    C c;   
}