#include <iostream>
#include <string>

using namespace std;

/*
Adder/Substractor/Multiply
- 부모가 run()으로 공통 흐름을 고정
- 자식은 실제 계산 방식
- 공통 흐름 : 제목출력 - 입력확인 - 계산 = 식 출력
*/

class Calculator{
protected:
    int a, b;
    virtual string getTitle() const = 0;
    virtual char getSymbol() const = 0;
    virtual int calc(int a, int b) const = 0;

public:
    void setValue(int x, int y){ a = x;  b = y; }
    void run() const {
        // 전체 실행 순서를 고정
        cout << "[" << getTitle() << "]" << endl;
        cout << a << " " << getSymbol() << " " << b << " = " << calc(a, b) << endl;
    }
    virtual ~Calculator() {}
};

class Adder : public Calculator {
protected:
    string getTitle() const override { return "ADDER"; }
    char getSymbol() const override { return '+'; }
    int calc(int a, int b) const override { return a + b; }
};

class Substractor : public Calculator {
protected:
    string getTitle() const override { return "SUBSTRACTOR"; }
    char getSymbol() const override { return '-'; }
    int calc(int a, int b) const override { return a - b; }
};

class Multiplier : public Calculator {
protected:
    string getTitle() const override { return "MULTIPLIER"; }
    char getSymbol() const override { return 'X'; }
    int calc(int a, int b) const override { return a * b; }
};

int main()
{
    Adder add;
    Substractor sub;
    Multiplier mul;

    Calculator* arr[3] = { &add, &sub, &mul };

    //부모 타임 포인터 배열로 자식 객체들을 한번에 다룰 수 있음
    for(int i = 0; i < 3; i++){
        arr[i]->setValue(20, 5);
        arr[i]->run();
    }

    return 0;
}