#include <iostream>
using namespace std;

class Trace{
private:
    int id;
public:
    Trace(int a) : id(a) { cout << "[Ctor] " << id << endl; }
    Trace() : id(1) { cout << "[Ctor] " << id << endl; }
    ~Trace() { cout << "[Dtor] " << id << endl; }
};

void func()
{
    Trace a;
    Trace b(100);
    cout << "Inside func" << endl;
}

int main()
{
    Trace m1(2);
    Trace m2(3);
    func();

    cout << "Back to main" << endl;

    return 0;
}
