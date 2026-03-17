#include <iostream>
using namespace std;

/*
동적할당 new + delete + 배열
2) 배열은 p[i]로 접근
3) delete [] p;   -> 힙에 저장된 배열 제거 (메모리 누수 방지)
4) delete [] 후  p = nullptr;    -> dangling pointer 방지
(실무 팁 : delete [] 후 p = nullptr; -> dangling pointer 방지)
*/

int main(){
    int n, sum = 0;

    cout << "How Many Integers? : ";
    cin >> n;
    if(n <= 0) return 0;

    int *p = new int[n];   // 힙에 int n개 저장

    for(int i=0; i<n; i++)
        cin >> p[i];   // 배열 요소에 입력

    for(int i=0; i<n; i++)
        sum += p[i];   // 배열 요소 합산

    cout << "Sum : " << sum << endl;
    cout << "Average : " << (double)sum / n << endl;

    delete [] p;   // 힙에 저장된 배열 제거 (메모리 누수 방지)
    p = nullptr;   // dangling pointer 방지

    return 0;
}