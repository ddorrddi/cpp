#include <iostream>

using namespace std;

class Circle{
private:
    int radius;
    static double pi;
public:
    Circle(int radius = 1) { this->radius = radius; }
    int getDiameter(Circle c) { return 2 * c.radius; }
    double getArea(Circle c) { return Circle::pi * c.radius * c.radius; }
};

double Circle::pi = 3.14;

int main()
{
    Circle circle = Circle(5);
    cout << circle.getDiameter(circle) << endl;
    cout << circle.getArea(circle) << endl;

    return 0;
}