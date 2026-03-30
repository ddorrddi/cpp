#include <iostream>
#include <string>

using namespace std;

/*
protect 접근 지정자
    - protected 멤버
1) 클래스 내부 접근 가능
2) 파생 클래스 내부 접근 가능
3) 외부 (함수 / 다른 클래스)에서는 접근 불가
*/

class Point{
protected:
    int x, y;
public:
    void set(int x, int y){ this->x = x; this->y = y; }
    void showPoint() const { cout << "(" << x << ", " << y << ")" << endl; }
};

class ColorPoint : public Point{
private:
    string color;
public:
    void setColor(string color) { this->color  = color; }
    void showColorPoint() const { cout << "Color : " << color << endl << "Point : "; showPoint(); }
    // 파생 클래스 내부라 (protected) x, y 직접 접근이 가능
    bool equals(const ColorPoint& p) const { return (x == p.x && y == p.y && color == p.color); }
};

int main()
{
    Point p;
    p.set(2, 3);
    // p.x;  -> 외부에서는 private처럼 접근 불가

    ColorPoint a;
    a.set(3, 4);
    a.setColor("RED");

    ColorPoint b;
    b.set(3, 4);
    b.setColor("RED");

    cout << (a.equals(b) ? "TRUE" : "FALSE") << endl;

    return 0;
}