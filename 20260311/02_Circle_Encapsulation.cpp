#include <iostream>
#define PI 3.141592

using namespace std;

class Circle{
private:
    int radius;
public:
    Circle(int r) { radius = r; }   // 생성자로 초기화
    int getRadius() { return radius; }   // 반지름을 반환하는 멤버 함수
    void setRadius(int r) { radius = r; }   // 반지름을 설정하는 멤버 함수
    double getArea() { return PI * radius * radius; }   // 원의 면적을 계산하는 멤버 함수
};

int main()
{
    Circle cir(5);
    cout << "Circle Radius : " << cir.getRadius() << "\n";
    cout << "Circle Area : " << cir.getArea() << "\n";

    return 0;
}