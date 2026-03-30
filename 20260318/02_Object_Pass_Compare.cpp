#include <iostream>

using namespace std;

class Circle{
private:
    int radius;
public:
    Circle() : radius(1) { }
    Circle(int r) : radius(r) { cout << "[C]" << radius << endl; }
    Circle(Circle& c) : radius( c.radius ) { cout << "[Copy C]" << radius << endl;}
    ~Circle() { cout << "[D]" << radius << endl; }

    int getRadius() const { return radius; }
    void setRadius(int r) { radius = r; }
};

// 값 전달: 복사본을 수정하므로 원본에 영향 없음
void increaseByValue(Circle c) {
    c.setRadius(c.getRadius() + 1);
}

// 참조 전달: 원본을 직접 수정
void increaseByRef(Circle& c) {
    c.setRadius(c.getRadius() + 1);
}

// 객체 비교: 반지름이 같으면 true
bool isSame(Circle c1, Circle c2) {
    return c1.getRadius() == c2.getRadius();
}

int main(){
    Circle waffle(30);
    cout << "Waffle Radius : " << waffle.getRadius() << endl;

    increaseByValue(waffle);
    cout << "Waffle Radius : " << waffle.getRadius() << endl;  // 30 유지

    increaseByRef(waffle);
    cout << "Waffle Radius : " << waffle.getRadius() << endl;  // 31

    Circle donut(31);
    cout << "Donut Radius : " << donut.getRadius() << endl;

    if (isSame(waffle, donut))
        cout << "waffle == donut" << endl;
    else
        cout << "waffle != donut" << endl;
}