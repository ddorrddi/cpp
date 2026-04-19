#include <iostream>
using namespace std;

/* 상속이 여러 단계인 때 virtual 선택
- virtual 함수는 가장 아래(가장 구체적인) 클래스의 구현이 선택된다.
- 같은 객체를 Base*, Derived* 등 어떤 타입의 포인터로 가리키더라도,
virtual 함수로 선언되어 있다면 항상 실제 생성된 객체의 가장 마지막(최하위) 오버라이딩 함수가 호출된다."
*/

class Base {
public:
    virtual void f() {cout << "Base::f() called\n"; }
};

class Derived : public Base {
public:
    void f() override { cout << "Derived::f() called\n"; }
};

class GrandDerived : public Derived {
public:
    void f() override {cout << "GrandDerived::f() called\n"; }
};

int main(){
    GrandDerived g;
    Base* bp = &g;
    Derived* dp = &g;
    GrandDerived* gp = &g;

    // 셋 다 같은 객체 g를 가리킨다.
    bp->f();
    dp->f();
    gp->f();

    return 0;
}