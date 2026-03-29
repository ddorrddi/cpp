#include <iostream>
#define PI 3.141592

using namespace std;

class Circle{
private:
    int radius;
public:
    Circle(int r) : radius(r) {}
    double getArea() const { return PI * radius * radius; }
};

int main()
{
    Circle c(3);
    cout << c.getArea() << endl;

    return 0;
}