#include <iostream>
#include <string>

using namespace std;

/*
상속 선언 : Point클래스 -> ColorPoint
1) class ColorPoint : public Point() -> public으로 받으면 그대로 다 받음 // public 상속
2) 파생 클래스 객체는 "기본 클래스 부분 + 파생 클래스 부분"을 함께 가짐
3) 기본 클래스의 private 멤버는 파생 클래스에서도 직접 접근 불가
    - public으로 받아도 priavte은 private으로 남음
4) 파생 클래스는 기본 클래스의 public 멤버 함수는 그대로 사용 가능
*/

class Point{
private:
    int x, y;
public:
    void set(int x, int y){ this->x = x; this->y = y; }
    void showPoint() const { cout << "(" << x << ", " << y << ")" << endl; }
};

class ColorPoint : public Point{
private:
    string color;
public:
    void setColor(string color) { this->color  = color; /* x = 1  ->  이것도 내부 private이기 때문에 접근 불가*/}
    void showColorPoint() const { cout << "Color : " << color << endl << "Point : "; showPoint(); }
};

int main()
{
    ColorPoint cp;
    cp.set(3, 4);           // basic에서 불림
    cp.setColor("RED");     // derived

    cp.showColorPoint();
    // cp.x;  ->  내부 private이어서 접근 불가

    return 0;
}