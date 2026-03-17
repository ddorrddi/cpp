#include <iostream>
#include <string>

using namespace std;

/*
--------------------------
문제 설명
1) 덧셈 문자열 (예 : "7+23+5+100")을 입력받아 합을 계산
 - find(ch/str, start) : start부터 문자/문자열 검색한 위치 반화느 없으면 npos
 - substr(pos, len) : pos부터 len만큼 반환
  -> find + substr + stoi로 문자아ㅕㄹ의 합 계산
2) '&'가 나올때까지 여러 줄 텐스트를 입력받고, 찾을 문자역을 다른 문자열로 모두 치환하여 출력
 - '&'가 나올 때까지 입력, 특정 문자열을 찾아 치환
  - replace(pos, len, repl): pos부터 len만큼 문자열을 repl로 치환
--------------------------
*/

int main(){
    // 덧셈 문자열 파싱
    cout << "Enter an addition string (e.g. 7+23+5) : ";
    string expr;
    getline(cin >> ws, expr);  //앞 공백 제거 후, 공백 포함 한줄 입력
    int sum = 0;
    int pos = 0;

    while(1){
        int plus = expr.find('+', pos);  //pos부터 + 검색

        if(plus == string::npos){  //더 이상 +가 없으면 마지막 숫자 처리 후 종료
            string part = expr.substr(pos);  //pos부터 끝까지 부분 문자열 추출
            sum += stoi(part);  //문자열을 int로 변환하여 합에 추가
            break;
        }

        string part = expr.substr(pos, plus - pos);  //pos부터 plus까지 부분 문자열 추출
        sum += stoi(part);  //문자열을 int로 변환하여 합에 추가
        pos = plus + 1;  //다음 숫자의 시작 위치 업데이트
    }

    cout << "Sum : " << sum << endl;

    // 멀티라인 find/replace
    cout << "Enter multiple lines of text (end with '&') : " << endl;
    string text, line;
    
    // getline(delimiter) : 구분자까지 입력받음, 구분자 제거
    getline(cin, line, '&');  // &가 나올 때까지 입력받음
    text += line;

    cout << "Find : ";
    string from;
    getline(cin >> ws, from);  //앞 공백 제거 후, 공백 포함 한줄 입력

    cout << "Replace : ";
    string to;
    getline(cin >> ws, to);  //앞 공백 제거 후, 공백 포함

    int idx = 0;
    while(1){
        // find(from, idx) : idx부터 from 검색 후 인덱스 반환
        idx = text.find(from, idx);
        if(idx == string::npos) break;
        // replace(idx, from.length(), to) : idx부터 from.length()만큼 문자열을 to로 치환
        text.replace(idx, from.length(), to);
        idx += to.length();  //치환된 문자열 뒤로 인덱스 이동
    }

    cout << "Result : " << endl << text << endl;

    return 0;
}