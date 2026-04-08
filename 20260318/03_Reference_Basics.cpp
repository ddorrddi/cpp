#include <iostream>

using namespace std;

/*
참조가 별명임을 확인
참조는 반드시 초기화해야하며 원본과 주소가 같다
*/

bool average(int a[], int size, int &avg){
    if(size <= 0) return false;

    int sum = 0;
    for(int i=0; i<size; i++)
        sum += a[i];

    avg = sum / size;
    
    return true;
}

int main(){
    int n = 1;
    int& ref = n;
    ref = 2;
    ref++;
    cout << "n = " << n << " / ref = " << ref << endl;

    int *p= &ref;
    *p = 20;
    cout << "n = " << n << " / ref = " << ref << endl;

    int x[] = {1, 2, 3, 4, 5};
    int avg;

    if(average(x, 5, avg)) cout << "Average : " << avg << endl;
    else cout << "Error" << endl;

    return 0;
}