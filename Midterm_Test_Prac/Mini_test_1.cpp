#include <iostream>

using namespace std;

class Accumulator{
private:
    int value;
public:
    Accumulator(int n) : value(n) {}
    Accumulator& add(int n) { 
        value += n;
        return *this; // 자기 자신을 돌려줘야해서 *this 사용 -> chaining
     }
    int get() { return value; }
};

int main()
{
    Accumulator acc(10);
    acc.add(5).add(6).add(7);
    cout << acc.get() << endl;
}