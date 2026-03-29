#include <iostream>
using namespace std;
/* 연산자 오버로딩은 기본(+, ==, +=)
- 연산자 오버로딩은 'operator연산자기호' 형태의 멤버 함수로 정의할 수 있다
- 'a + b'는 멤버 함수로 쓰면 'a.operator + (b)'차람 헤석됨.
- 'a == b'는 'a.operator == (b)'처럼 해석
- 'a += b'는 'a.operator += (b)'처럼 해석
*/

class Power{
private:
    int kick;
    int punch;
public:
    Power(int k = 0, int p = 0) : kick(k), punch(p) {}
    void show() const {cout << "kick = " << kick << ", punch = " << punch << "\n"; }
    // 멤버 연산자 함수
    // 변환형 operator연산자기호(오른쪽피연산자) [const]
    // a + b -> a.operator{b}
    Power operator+(const Power& op2) const {
        // a + b -> 세로운 Power로 생성
        return Power(kick + op2.kick, punch + op2.punch);
    }
    // ==는 비교해서 bool 변환
    bool operator == (const Power& op2) const {
        return (kick == op2.kick && punch == op2.punch);
    }

    // +=는 왼쪽 객체 자신을 바꾸는 연산
    // "자기 자신을 수정"하는 연산에서는 참조 반환이 많음
    Power operator+=(const Power& op2){
        kick += op2.kick;
        punch += op2.punch;
        return *this;
    }
};

int main(){
    Power a(3, 5), b(4, 6), c;

    c = a + b;

    a.show();
    b.show();
    c.show();

    // a == b -> a.operator == (b)
    cout << (a == b ? "same\n" : "diff\n");

    // a + b -> a.operator += (b)
    a.show();
    b.show();

    c = (a += b);

    a.show();
    b.show();
    c.show();

    a += b;

    (a += b) += c;
    a.show();
    b.show();
    c.show();

    return 0;
}