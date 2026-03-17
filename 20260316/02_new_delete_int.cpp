#include <iostream>

using namespace std;

/*
동적할당 new + deleete
1) int *p = new int;   -> 힙에 int 한 개 저장
2) *p = 5;             -> 힙에 저장된 int에 5 저장
3) delete p;           -> 힙에 저장된 int 제거 (메모리 누수 방지)
4) delete 후  p = nullptr;    -> dangling pointer 방지
(실무 팁 : delete 후 p = nullptr; -> dangling pointer 방지)
*/

int main() {
    int *p = new int;   // 힙에 int 한 개 저장
    *p = 5;             // 힙에 저장된 int에 5 저장
    cout << "*p: " << *p << endl;   // *p: 5

    delete p;           // 힙에 저장된 int 제거 (메모리 누수 방지)
    p = nullptr;        // dangling pointer 방지

    return 0;
}