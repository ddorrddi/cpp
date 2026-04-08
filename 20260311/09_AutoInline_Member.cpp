#include <iostream>
#define PI 3.141592

using namespace std;

class Circle{
private:
    int radius;
public:
    Circle(int r) : radius(r) {}    // 클래스 선언부 내부 구현 -> 자동 인라인 후보
    double getArea() const { return PI * radius * radius; }
};

int main()
{
    Circle c(3);
    cout << c.getArea() << endl;

    return 0;
}