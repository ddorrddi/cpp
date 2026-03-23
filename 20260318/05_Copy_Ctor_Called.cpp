#include <iostream>
#include <string>
using namespace std;

/*
복사생성자 : 언제 자동 호출되는가?
1) 복사 생성자 형태 : ClassName(const ClassName& other);
2) 자동 호출 대표 상화
 - Person son = father;  // 대입연산자 초기화
 -functon(father); // 값 전달
*/

class Person{
    string name;
public:
    Person(string n) : name(n) { }
    Person (const Person& p) : name(p.name) { cout << "Copy Ctor Called : " << name << endl; }

};

void function(Person p) {
    cout << "Function Called" << endl;
}

int main()
{
    Person father("HwiHwi");
    Person son = father;  // 복사 생성자 호출

    function(son);

    return 0;
}