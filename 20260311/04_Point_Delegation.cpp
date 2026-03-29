#include <iostream>

using namespace std;

class Point{
private:
    int x, y;
public:
    Point() : Point(0,0) { } // : 사용은 바로 초기화 
    Point(int a, int b) : x(a), y(b) { }
    void show() const { cout << "(" << x << ", " << y << ")\n"; }
    // const가 나오면 수정 x 오로지 읽기만 -> 출력만 있을 때 사용
};

int main()
{
    Point origin;
    Point target(10, 20);
    origin.show();
    target.show();

    return 0;
}