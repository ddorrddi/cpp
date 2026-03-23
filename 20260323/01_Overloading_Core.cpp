#include <iostream>

using namespace std;

/*
오버로딩 핵심
1) 핵심 이름이 같아도 매개변수의 개수나 타입이 다르면 공존할 수 있다.
2) 컴파일러는 "호출하는 모양"을 보고 어떤 함수를 부를 지 결정
3) 리턴 타입은 호출 시점에 보이지 않으므로 오버로딩 기준이 될 수 없다.
4) 같은 이름으로 묶는 것이 가능하더라도, 의미를 너무 많이 담으면 섞일 수 있다.
*/

void printTitle(const char* title){
    cout << "[ " << title << " ]" << endl;
}

/*-------------------------------------------------------*/

namespace BasicSum{
    int sum(int a, int b) { return a+b; }
    int sum(int a, int b, int c) { return a+b+c; }
    double sum(double a, double b) { return a+b; }
}

/*-------------------------------------------------------*/

namespace RangeExample{
    // 매개변수 하나
    int sum(int last){
        int total = 0;
        for(int i = 0; i <= last; i++)
            total += i;
        return total;
    }
    // 매개변수 두개
    int sum(int first, int last){
        int total = 0;
        for(int i = first; i <= last; i++)
            total += i;
        return total;
    }
}

/*-------------------------------------------------------*/

namespace BigOne{
    int big(int a, int b) { return (a > b) ? a : b; }
    int big(const int values[], int size){
        int result = values[0];
        for(int i = 1; i < size; i++)
            if(values[i] > result)
                result = values[i];
        return result;
    }
}

/*-------------------------------------------------------*/

int main()
{
    // 컴파일러가 호출 모양을 어떻게 해석하는지 유의
    printTitle("STANDARD OVERLOADING");
    cout << "SUM(2, 6) = " << BasicSum::sum(2, 6) << endl;
    cout << "SUM(2, 6, 33) = " << BasicSum::sum(2, 6, 33) << endl;
    cout << "SUM(12.5, 33.6) = " << BasicSum::sum(12.5, 33.6) << endl;

    // 의미가 다른 sum 오버로딩
    printTitle("OVERLOADING WITH DIFFERENT MMEANING");
    cout << "RangeExample : " << RangeExample::sum(3) << endl;
    cout << "RangeExample : " << RangeExample::sum(3, 5) << endl;

    // 배열 버전은 매개변수 형태가 완전히 다르므로 다른 함수로 구분된다.
    printTitle("OVERLOADING WITH DIFFERENT TYPE");
    int values[5] = { 1, 2, 3, 4, 5};
    cout << "BIG(2, 3) = " << BigOne::big(2, 3) << endl;
    cout << "BIG(values, 5) = " << BigOne::big(values, 5) << endl;
    
    return 0;
}