#include <iostream>
#include <string>

using namespace std;

/*
업캐스팅 : Derived 클래스의 *(포인터 / 주소) -> Base* 로 사용
1) 업캐스팅 자동 변환 가능 : Point* p = (ColorPoint*)&cp;
2) Base*로 접근할 때는 Base에 존재하는 멤버만 호출 가능
    - 파생 클래스만 가진 멤버는 호출 불가
3) 업캐스팅은 "여러 파생 객체를 하나의 기반 타입으로 묶어 다루기 위해 필요한 것"
    - 공통 기능을 기준으로 처리할 때 쓰임
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

void printPoint(Point* p){ p->showPoint(); }

int main()
{
    ColorPoint cp;
    ColorPoint* pDer = &cp;
    
    //cp는 ColorPoint 객체이므로, Point 부분도 함께 가짐
    Point* pBase = pDer;    // 자동 업캐스팅
    pDer->set(3, 4);
    pBase->showPoint();
    
    pDer->setColor("RED");
    pDer->showColorPoint();

    //pBase는 Point로 보고 있으므로 , Point에 있는 멤버만 호출 가능
    // pBase->showColorPoint(); -> Base에는 없는 멤버라 에러

    Point p;
    p.set(1, 2);
    printPoint(&p);
    printPoint(&cp);

    return 0;
}