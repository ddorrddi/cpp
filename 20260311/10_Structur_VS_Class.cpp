#include <iostream>

using namespace std;

/*
class와 struct는 거의 동일하지만 디폴트 접근 지정이 다름
class : private
struct : public
*/

class C{
private:
    int x;
public:
    C(int a) : x(a) {}
    int getX() { return x; }
};

struct S{
    int x;
    S(int a) : x(a) {}
};

int main()
{
    C c(10);
    // cout << c.x; -> x는 private이라 에러
    cout << c.getX() << endl; //public 함수로 원하는 값 반환

    S s(20);
    cout << s.x << endl; //public이므로 출력 가능
}