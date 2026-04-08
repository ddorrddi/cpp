#include <iostream>
using namespace std;
/*
    객체 포인터 + 객체 배열 + 배열 초기화
1) 객체 포인터  : -> 와 (*p) .
2) 객체 배열    : 기본 생성자 호출 (Circle())
3) 배열 초기화  : 
*/

class Circle{
    int raius;
public:
    Circle() : raius(1) {}
    Circle(int r) : raius(r) {}
    void setRaius(int r) { raius = r; }
    double getArea() { return 3.14 * raius * raius; }
};

int main(){
    Circle donut;
    Circle pizza(30);

    Circle* p = &donut;     //donut 주소 저장
    cout << "[obj] donut area : " << donut.getArea() << endl;  //donut 면적 출력
    cout << "[ptr] donut area : " << p->getArea() << endl;     //포인터로 donut 면적 출력
    cout << "[ptr] donut area : " << (*p).getArea() << endl;   //포인터로 donut 면적 출력

    p = &pizza;     //pizza 주소 저장
    cout << "[obj] pizza area : " << pizza.getArea() << endl;  //pizza 면적 출력
    cout << "[ptr] pizza area : " << p->getArea() << endl;
    cout << "[ptr] pizza area : " << (*p).getArea() << endl;

    cout << "--------Object Array--------" << endl;
    Circle arr[3];
    cout << "Circle area : " << arr[0].getArea() << endl;
    arr[0].setRaius(10);
    cout << "Circle area : " << arr[0].getArea() << endl;
    for(int i=0; i<3; i++){
        cout << "Circle " << i+1 << " area : " << arr[i].getArea() << endl;
    }
    for(int i=0; i<3; i++){
        arr[i].setRaius((i+1)*10);
    }
    for(int i=0; i<3; i++){
        cout << "Circle " << i+1 << " area : " << arr[i].getArea() << endl;
    }
    cout << "--------Object Array + Pointer--------" << endl;
    Circle* ap = arr;   // 배열 이름은 배열의 첫 번째 요소의 주소를 가리킴
    for(int i=0; i<3; i++){
        cout << "Circle " << i+1 << " area : " << ap->getArea() << endl;
        ap++;   //다음 요소로 이동
    }

    // 원소별 생성자 직접 지정
    cout << "--------Object Array + Pointer + Initialization--------" << endl;
    Circle initarr[3] = { Circle(10), Circle(20), Circle(30) };
    for(int i=0; i<3; i++){
        cout << "Circle " << i+1 << " area : " << initarr[i].getArea() << endl;
    }

    cout << "--------2D Object Array + Initialization--------" << endl;
    // 2차원 배열
    Circle Circles[2][3];
    int r = 10;
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            Circles[i][j].setRaius(r);
            r += 10;
        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            cout << "Circle[" << i << "][" << j << "] area : " << Circles[i][j].getArea() << endl;
        }
    }
    
    cout << "--------2D Object Array + Initialization + Constructor--------" << endl;
    Circle circles[2][3] = {
        { Circle(10), Circle(20), Circle(30) },
        { Circle(40), Circle(50), Circle(60) }
    };

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            cout << "Circle[" << i << "][" << j << "] area : " << circles[i][j].getArea() << endl;
        }
    }

    return 0;
}