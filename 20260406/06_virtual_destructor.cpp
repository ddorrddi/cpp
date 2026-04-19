#include <iostream>

using namespace std;

/* 가상 소멸자: Base*로 delete를 할 가능성이 있으면 필수
핵심
- Base* bp = new Derived();
- delete bp;를 할 수 있다면, Base 소멸자는 반드시 virtual이어야 함.
그렇지 않으면 Derived 소멸자가 호출되지 않아 자원 해제 누락 가능.
- 실무에서는 "가상 함수를 하나라도 가진 부모 클래스"라면 소멸자도 virtual 두는 경우가 많다.
*/

class Base{
public:
    virtual ~Base() { cout << "~Base()\n"; }
};

class Derived : public Base {
public:
    ~Derived() override { cout << "~Derived()\n"; }
};

int main(){
    Derived* dp = new Derived();
    Base* bp = new Derived();

    delete dp;
    delete bp;
    return 0;
}