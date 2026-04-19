#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
STL 알고리즘 sort(begin, end)
- sort는 <algorithm> 헤더의 전역 함수 템플릿
- sort(v.begin(), v.end()) [begin, end) // end는 포함안하기 때문에 저 형식으로 써야함
- 기본은 오름차순(원소의 operator< 사용) // operator< 만 정의 되어있다면 무엇이든지 sorting 가능
- 내림차순은 sort(..., greater<int>())
*/

int main(){
    vector<int> v;
    cout << "5 number of inputs: ";
    for(int i=0;i<5;i++){
        int n; cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());

    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
        cout << *it << ' ';
    cout << endl;

    //greater<int>() 비교자를 주면 내림차순 정렬 가능
    sort(v.begin(), v.end(),greater<int>());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
        cout << *it << ' ';
    cout << endl;

    return 0;
}