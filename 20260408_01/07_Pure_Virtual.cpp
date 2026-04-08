#include <iostream>

using namespace std;

/*
순수 가상함수와 추상 클래스
핵심 내용
- virtual void draw() = 0; -> 순수 가상 함수
- 순수 가상함수를 가진 클래스는 추상 클래스 -> 객체 생성 불가
- 기능 이름은 정하지만 구현은 자식에게 맡김
- 하지만 포인터/참조는 만들 수 있고 파생 클래스에서 구현하면 사용 가능
- 추상클래스 소멸자도 virtual로 두는 것이 안전한 관례
*/

class Shape{
public:
    virtual void draw() = 0;        // 구현은 없지만 공통 흐름은 일반 멤버 함수로 제공할 수 있음
    void paint() { draw(); }
    virtual ~Shape() {}
};

class Circle : public Shape{
public:
    void draw() override { cout << "Circle" << endl; }
};

int main()
{
    // Shape s;        // 추상 클래스 객체 생성 불가
    Shape* p = new Circle();
    p->paint();

    return 0;
}