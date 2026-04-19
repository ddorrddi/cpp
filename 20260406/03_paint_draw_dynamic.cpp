#include <iostream>
using namespace std;
/* Base 멤버 함수 안에서 virtual 호출이 일어나는 구조
- 부모 함수 안에서 virtual 함수를 호출
- 이 구조는 "공통 흐름은 부모가, 세부 동작은 자식이" 맡는 설계의 기본
*/
class Shape {
public:
    void paint() { draw(); } // 공통의 흐름 담당
    virtual void draw() { cout << "Shape::draw() called\n"; }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Circle::draw() called\n"; }
};

int main(){
    Shape* p1 = new Shape();
    p1->paint();
    delete p1;

    Shape* p2 = new Circle();
    p2->paint(); // paint() Shape의 함수지만, 내부 draw는 Circle버전이 선택
    delete p2;
    return 0;
}