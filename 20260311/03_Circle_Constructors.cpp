#include <iostream>
#define PI 3.141592

using namespace std;

class Circle{
private:
    int radius;
public:
    Circle(int r) { radius = r; }
    Circle() { radius = 1; }
    double getArea() { return PI * radius * radius; }
    void setRadius(int r) { radius = r; }
    int getRadius() { return radius; }
};

int main()
{
    Circle donut, pizza(10);
    cout << "Donut Radius : " << donut.getRadius() << endl;
    cout << "Donut Area : " << donut.getArea() << endl;
    cout << "Pizza Radius : " << pizza.getRadius() << endl;
    cout << "Pizza Area : " << pizza.getArea() << endl;

    return 0;
}