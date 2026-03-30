#include <iostream>
#define PI 3.141592
using namespace std;

/*
1) 객체 리턴과 대입
 - getCircle()
*/

class Circle{
private:
    int radius;
public:
    Circle() : radius(1) {}
    Circle(int r) : radius(r) {}
    Circle(Circle& c) : radius( c.radius ) {}
    ~Circle() {}

    int getRadius() const { return radius; }
    void setRadius(int r) { radius = r; }
    double getArea() const { return PI * radius * radius; }
    // 참조 반환을 통한 메서드 체이닝
    // - 리턴타입이 Circle& (자신의 참조) -> 호출 후 같은 객체 조작 가능
    // - return *this : this 포인터가 가리키는 객체(자신)의 참조 반환
    // - 체이닝 원리 : a.plus(1).plus(2)
    Circle& plus(int n){
        radius += n;
        return *this;  // 자신의 참조 반환
    }
};

Circle getCircle() {
    Circle tmp(30);
    return tmp;  // 객체 리턴
}

char g = 'a'; // 전역변수
// 참조 반환 : 전역 변수 g의 공간 자체를 반환 (복사 아님)
char& findGlobal(){
    return g;  // 참조 리턴
}

char& findAt(char s[], int idx){
    return s[idx];  // 참조 리턴
}

int main()
{
    Circle c = getCircle();
    cout << c.getArea() << endl;

    c = getCircle();  // 대입 연산자 호출
    cout << c.getArea() << endl;

    char a = g;
    cout << "a = " << a << endl;
    findGlobal() = 'b';  // 참조 반환을 이용한 전역 변수 수정
    cout << "g = " << g << endl;

    char name[] = "HwiHwi";
    cout << "NAME : " << name << endl;
    //배열의 0번 인덱스의 원소를 직접 수정
    findAt(name, 0) = 'S';
    cout << "NAME : " << name << endl;
    //참조를 받아 수정하면 같은 원소가 바뀜
    char& ref = findAt(name, 2);
    ref = 'M';
    cout << "NAME : " << name << endl;

    // 객체 자신 참조 리턴 (체이닝)
    Circle Cir_A(100);
    Cir_A.plus(1).plus(2).plus(3);  // Cir_A의 반지름이 106이 됨
    cout << "Cir_A Area : " << Cir_A.getArea() << endl;
    
    return 0;
}