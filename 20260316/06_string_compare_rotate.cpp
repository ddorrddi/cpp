#include <iostream>

using namespace std;

/*
--------------------------
문제 설명
1) 단어 n개를 입력 받아 사전식으로 가장 작은 단어와 가장 큰 단어 출력
    - string 비교 (<,>)는 사전식 기준이다
2) 문자역 s와 정수 k를 입력받아, s를 왼쪽으로 k칸 회전한 결과를 출력
--------------------------
- substr(pos) : pos부터 끝까지 반환
- substr(pos, len) : pos부터 len만큼 반환
*/

int main(){
    int n;
    cout << "How Many Words? : ";
    cin >> n;

    if(n <= 0) return 0;

    string first;
    cin >> first;
    string minWord = first;
    string maxWord = first;

    for(int i=1; i<n; i++){
        string word;
        cin >> word;
        // 사전식 비교
        if(word < minWord) minWord = word;      //사전식 최소
        if(word > maxWord) maxWord = word;      //사전식 최대
    }

    cout << "Minimum word: " << minWord << endl;
    cout << "Maximum word: " << maxWord << endl;

    // (2) 문자열 회전 (왼쪽 회전)
    string s;
    int k;
    cout << "String to rotate and k : ";
    cin >> s >> k;

    if(!s.empty()){
        string rotatted = s.substr(k) + s.substr(0, k);  //왼쪽으로 k칸 회전
        cout << "Rotated string: " << rotatted << endl;
    }

    return 0;
}