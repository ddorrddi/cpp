#include <iostream>

using namespace std;

class PrivateAccessError{
private:
    int a;
    void f() { a = 5; }
    PrivateAccessError() { a = 1; b = 1;}
public:
    int b;
    PrivateAccessError(int x) { a = x; b = x; }
    void g() { a = 6; b = 6; }
};

int main()
{
    // PrivateAccessError objA; -> private 생성자라 생성 불가
    PrivateAccessError objB(5);

    // objB.a = 10; -> a는 private
    objB.b = 20;

    // objB.f(); -> f()는 private
    objB.g();

    cout << "b = " << objB.b << endl;

    return 0;
}