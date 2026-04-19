#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
템플릿 함수와 vector를 함께 사용
---------------------------------
문제 상황
- 어떤 반의 시험 점수 목록에서 최고 점수를 찾고 싶다.
- 학생 이름 목록에서 사전순으로 가장 뒤에 오는 이름도 찾고 싶다.
--> 두 문제는 "자료타입"만 다르고, "목록에서 가장 큰 값을 찾는다"는 작업은 같다. 이러면 templete으로 만들면 됨
*/


template <class T>
void printVector(const vector<T>& v, const string& title){
    //todo
    cout << "title: " << title << endl;
    for(typename vector<T>::const_iterator it=v.begin();it!=v.end();it++)
        cout << *it << " ";
}

template <class T>
T getMaxVector(const vector<T>& v){
    //todo
    T max=v.at(0);
    for(typename vector<T>::const_iterator it=v.begin();it!=v.end();it++)
        if(*it>max)
            max=*it;
    return max;

}


int main(){
    // 문제 1: 시험 점수 목록에서 최고점 찾기
    vector<int> scores;
    scores.push_back(88);
    scores.push_back(75);
    scores.push_back(92);
    scores.push_back(85);
    printVector(scores, "scores: ");
    cout << "max scores: " << getMaxVector(scores) << endl;

    // 문제 2: 이름 목록에서 사전순으로 가장 뒤 이름 찾기
    vector<string> names;
    names.push_back("Kim");
    names.push_back("Lee");
    names.push_back("Park");
    names.push_back("Choi");
    printVector(names, "Names: ");
    cout << "max name: " << getMaxVector(names) << endl;
    return 0;
}