#include <iostream>
using namespace std;
/* virtual이 있을 때: 오버라이딩 + 동적바인딩
- 동적 바인딩은 "실행시점"에 실제 객체 타입을 보고 함수를 고른다.

예제:
- Base::f()를 virtual로 선언하면,
Base*로 호출해도 "실제 객체 타입"에 맞는 함수가 실행
- 즉 Base*가 Derived 객체를 가리키면 Derived::f()가 실행

override 키워드
-오버라이딩이 맞는지 컴파일러가 검사해줌.
*/
class Base {
public:
    virtual void f() {cout << "Base::f() called\n"; }
};

class Derived : public Base {
public:
    void f() override { cout << "Derived::f() called\n"; }
};
    
int main(){
    Derived d;
    Derived* pDer = &d;
    pDer->f(); // Derived

    Base* pBase = pDer; // 업캐스팅
    pBase->f(); // Derived!!!

    return 0;
}