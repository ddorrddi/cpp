#include <iostream>
#include <vector>

using namespace std;

/*
vector<int> 기본
- push_back : 끝에 추가
- size : 원소 개수
- v[i] : 범위 체크 없음
- v.at(i) : 범위 체크 ( 잘못 되면 예외 가능 )
*/

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    v[0] = 10;
    v.at(2) = 5;
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}