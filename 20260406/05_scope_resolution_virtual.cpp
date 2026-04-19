#include <iostream>

using namespace std;

/* 범위 지정(::)으로 Base의 virtual 함수를 강제로 호출
p->draw()는 동적 바인딩 -> 실제 객체 타입의 draw()
p->Shape::draw()는 정적 바인딩 -> Base의 draw()를 강제 실행
*/

class Shape {
public:
    void paint() { draw(); } // 공통의 흐름 담당
    virtual void draw() {cout << "Shape::draw() called\n"; }
};

class Circle : public Shape {
public:
    void draw() override { 
        Shape::draw(); // 부모 버전을 명시적 호출
        cout << "Circle\n"; }
};

int main(){
    Circle circle;
    Shape* p = &circle;

    p->draw(); // 동적바인딩
    p->Shape::draw(); // 정적바인딩, 범위 지정으로 부모버전 호출
    return 0;
}