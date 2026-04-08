#include <iostream>

using namespace std;

// 동적 객체 : new Circle(...) / delete
// 동적 객체 배열 : new Circle[n] / delete[]
/*
this pointer : 객체 자신을 가리키는 포인터, 멤버 함수 내에서 사용
1) this는 "현재 멤버 함수를 실행중인 객체 자신"을 가리키는 포인터
2) 매개변수 이름과 멤버 이름이 같을 때 : 
    this->radius = radius; (멤버 radius에 매개변수 radius를 대입)
3) return this; (매서드 체이닝 등에서 사용 가능)
*/ 

class Circle{
private:
    int radius;
public:
    Circle() : radius(1) { cout << "--------Circle Created (r = 1)--------\n";}
    Circle(int r) { this->radius = r; cout << "--------Circle Created (r = " << radius << ")--------\n"; }
    ~Circle() { cout << "--------Circle Destroyed (r = " << radius << ")--------\n"; }
    void setradius(int r) { this->radius = r; }
    double getArea() { return 3.14 * this->radius * this->radius; }
    Circle* self() { return this; }  //this 반환 예시
};

int main(){
    int r;

    cout << "--------Dynamic Object--------" << endl;
    while(1){
        cout << "radius (negative to exit) : ";
        cin >> r;
        if(r < 0) break;
        Circle *p = new Circle(r);   //동적 객체 생성
        cout << "Circle area : " << p->getArea() << endl;

        delete p;  //동적 객체 소멸
    }

    cout << "--------Dynamic Object Array--------" << endl;
    int n;
    cout << "number of circles : ";
    cin >> n;
    
    if(n <= 0 ) return 0;
    Circle* arr = new Circle[n];   //동적 객체 배열 생성

    for(int i=0; i<n; i++){
        int r;
        cin >> r;
        arr[i].setradius(r);
    }

    for(int i=0; i<n; i++){
        cout << "Circle " << i+1 << " area : " << arr[i].getArea() << endl;
    }

    delete[] arr;  //동적 객체 배열 소멸

    cout << "--------this pointer example--------" << endl;

    Circle c1;
    Circle c2(3);

    c1.setradius(5);
    c1.setradius(8); //매개변수 이름과 멤버 이름이 같을 때 this 사용 예시

    cout << (c1.self() == &c1 ? "same" : "different") << endl; //this 반환 예시
    return 0;
}