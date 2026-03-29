#include <iostream>
using namespace std;

class Power{
private:
    int kick;
    int punch;
public:
    Power(int k = 0, int p = 0) : kick(k), punch(p) {}
    void show() const {cout << "kick = " << kick << ", punch = " << punch << "\n"; }
    
    // ++a -> 외부함수 a.operator++(a)
    friend Power& operator++(Power& op);
     // ++a -> 외부함수 a.operator++(a, 0)
    friend Power operator++(Power& op, int); 
};

Power& operator++(Power& op){
    op.kick++;
    op.punch++;
    return op;
}

Power operator++(Power& op, int){
    Power tmp = op;
    op.kick++;
    op.punch++;
    return tmp;
}

int main(){
    Power a(3, 5), b;

    b = ++a;
    a.show();
    b.show(); // 전위

    b = a++;
    a.show();
    b.show(); // 후위

    return 0;
}