#include <iostream>

using namespace std;

/*
static 공유 멤버와 클래스 스코프 접근
1) 일반 멤버는 객체마다 따로 존재하지만, static 멤버는 클래스 전체가 하나를 공유
2) 따라서 static 값은 어느 객체로 접근하든 결국 같은 데이터를 가짐
3) static 멤버는 객체 없이도 존재하므로, '클래스명::멤버' 형태로 접근할 수 있음
4) static 멤버 변수는 선언만으로 끝나지 않고 클래스 밖에서 한번 정의해야함
*/

class Person{
public:
    int money;
    static int sharedMoney;

    Person(int money = 0) : money(money) {}
    void addMoney(int amount) { money += amount; }
    static void addShared(int amount) { sharedMoney += amount; }    // 이 함수는 특정 객체가 아닌 클래스 전체의 sharedMoney를 바꿈
    static void printShared() { cout << "SHARED MONEY : " << sharedMoney << endl; }
};

int Person::sharedMoney = 10;   // static 멤버 변수는 클래스 밖에서 한번 정의해야 실제 저장공간이 생김

int main()
{
    Person HWI(100);
    Person HO(150);

    HWI.addMoney(50);
    HO.addMoney(200);

    cout << "HWI MONEY : " << HWI.money << endl;
    cout << "HO MONEY : " << HO.money << endl;

    //sharedMoney는 클래스 전체가 공유하는 하나의 값이다.
    HWI.sharedMoney = 200;
    cout << "HWI SHARED MONEY : " << HWI.sharedMoney << endl;
    cout << "HO SHARED MONEY : " << HO.sharedMoney << endl;

    // 객체 없이도 클래스명으로 static 접근
    Person::addShared(100);
    Person::printShared();

    Person::sharedMoney = 500;
    cout << Person::sharedMoney << endl;
    cout << HWI.sharedMoney << endl;

    return 0;
}