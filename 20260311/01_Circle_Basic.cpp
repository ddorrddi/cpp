#include <iostream>

using namespace std;

// (상태) 멤버 변수
// (행동) 멤버 함수 원형
// 클래스 밖에서 멤버 함수 구현: 범위지정 연산자 ::

class Circle {
public:
    int radius;
    double getArea();
};

double Circle::getArea() {
    return 3.14 * radius * radius;
}

int main() 
{
    Circle donut;   // 객체 생성
    donut.radius = 1;   // 멤버 변수 접근
    cout << "donut area = " << donut.getArea() << "\n"; // 멤버 함수 호출
    Circle pizza;
    pizza.radius = 30;
    cout << "pizza area = " << pizza.getArea() << "\n";
}