#include <iostream>
using namespace std;

/*
static 활용
1) 객체 상태가 필요없는 함수는 static 멤버 함수로 묶어 유틸리티처럼 사용 가능
2) static 변수는 객체수와 상관없이 하나만 존재하므로 개수 세기 같은 역할에 적합
3) static 함수는 객체 없이 호출되므로 this 포인터가 없다.
4) 따라서 static 함수는 
*/

class Math{
public:
    // 객체 상태가 필요없는 함수는 static으로 묶어두면 사용이 분명해진다.
    static int abs(int a) { return (a > 0) ? a : -a; }
    static int max(int a, int b) { return (a > b) ? a : b; }
    static int min(int a, int b) { return (a < b) ? a : b; }
};

class Circle{
private:
    static int numofCircles;
    int radius;
public:
    Circle(int r = 1) : radius(r) { numofCircles++; }
    ~Circle() { numofCircles--;}
    static int getNumOfCircles() { return numofCircles; }
    int getRadius() const { return radius; }
};

int Circle::numofCircles = 0;

class PersonError{
private:
    int money;
public:
    PersonError() : money(0) {}
    void setMoney(int amount) { money = amount; }

    // static 함수는 this가 없어서 non-static 멤버를 직접 읽을 수 없음
    // 필요한 객체를 인자로 받으면 그 객체의 값을 읽는 것은 가능
    static int getMoney(const PersonError person) { return person.money; }
};

int main()
{
    // 전역함수처럼 보이는 기능을 클래스 안  static으로 정리한 예제
    cout << "MATH::abs(-5) = " << Math::abs(-5) << endl;
    cout << "MATH::max(10, 8) : " << Math::max(10, 8) << endl;
    cout << "MATH::min(-10, -5) : " << Math::min(-10, -5) << endl;
    cout << "----------------------------------------" << endl;

    //static 변수는 객체스와 무관하게 하나만 있어서, 카운터 역할에 적합
    cout << "INITIAL COUNT : " << Circle::getNumOfCircles() << endl;
    {
        Circle a;
        Circle b(5);
        cout << "COUNT INSIDE OF BLOCK : " << Circle::getNumOfCircles() << endl;
    }
    
    // 블럭 을 벗어나면 지역 객체가 소멸
    cout << "COUNT OUTSIDE OF BLOCK : " << Circle::getNumOfCircles() << endl;

    Circle *arr = new Circle[3];
    cout << "COUNT AFTER ARRAY : " << Circle::getNumOfCircles() << endl;
    delete[] arr;
    cout << "COUNT AFTER ARRAY DELETE : " << Circle::getNumOfCircles() << endl;
    cout << "----------------------------------------" << endl;
    
    PersonError person;
    person.setMoney(100);
    cout << "GetMoney(person) : " << PersonError::getMoney(person) << endl;

    return 0;
}