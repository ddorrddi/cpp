#include <iostream>
#include <vector>
using namespace std;
/*
한개의 반의 시험 점수 목록에서 최소 점수를 찾고 싶다
1) vector<int> 에 시험 점수 저장
2) printScores(), getMaxScores()
*/

void printScores(const vector<int>& scores, const string& title){
    cout << "title: " << title;
    //todo
    for(vector<int>::const_iterator it=scores.begin();it!=scores.end();it++) // iterator를 쓸때 읽기전용이면 const_iterator 써야한다.
        cout << *it << " ";
    cout << endl;
}

int getMaxScores(const vector<int>& scores){
    int maxScore = scores.at(0);
    // todo
    for(vector<int>::const_iterator it=scores.begin()+1;it!=scores.end();it++) // it는 포인터니까 시작점을 +1을 해줘야한다.
        if(*it>maxScore)
            maxScore=*it;
    return maxScore;
}

int main(){
    vector<int> scores;
    scores.push_back(88);
    scores.push_back(75);
    scores.push_back(92);
    scores.push_back(85);
    printScores(scores, "scores: ");
    cout << "max scores: " << getMaxScores(scores) << endl;

    return 0;
}