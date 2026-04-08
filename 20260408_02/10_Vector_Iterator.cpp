#include <iostream>
#include <vector>

using namespace std;

/*
iterator로 vector 순회하며 값 수정
- vector<int>::iterator it
- v.begine() : 첫번째 원소를 가리키는 iterator 반환
- v.end() : 마지막 원소가 아니라 그 "다음 위치"를 가리키는 iterator 반환
- it= v.begin(); it != v.end(); it++
- *it으로 원소 접근
*/

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
        *it = (*it) * 2;
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}