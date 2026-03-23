#include <iostream>

using namespace std;

/*
디폴트 인자를 이용한 생성자 간소화
1) 생성자에도 Default 매개변수를 줄 수 있음
*/

class MyVector{
private:
    int *p;
    int size;
public:
    MyVector(int n = 100){
        p = new int[n];
        size = n;
        // 0으로 초기화
        for(int i = 0; i < size; i++)
            p[i] = 0;
    }
    ~MyVector() { delete[] p; }
    int getSize() const { return size; }
    void set(int index, int value) { p[index] = value; }
    void printPreview(int count) const {
        cout << "VALUE : ";
        for(int i = 0; i < count; i++)
            cout << p[i] << ' ';
        cout << endl;
    }
};

int main()
{
    // 같은 생성자라도 인수 유무에 따라 다른 초기화 가능
    MyVector v1;
    MyVector v2(8);

    v1.set(0, 100);
    v1.set(1, 200);
    v2.set(0, 5);
    v2.set(1, 6);

    cout << "V1 size : " << v1.getSize() << endl;
    v1.printPreview(5);

    cout << "V2 size : " << v2.getSize() << endl;
    v2.printPreview(5);
    
    return 0;
}