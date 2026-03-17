#include <iostream>
#include <string>

using namespace std;

/*
string 기본 +입력 + stoi
1) string : 가변 길이 문자열 클래스
2) append/lenhth 사용
    append(str) : 문자열 뒤에 str 추가
    length() : 문자열 길이 반환 (size()도 동일)
3) getline(cin >> ws, str)로 앞 공백 제거 후, 공백 포함 한줄 입력
4) stoi(str)로 문자열을 int로 변환
*/

int main(){
    // 1) string 생성/복사
    string str;
    string address("Kookmin University");
    string copyAddress(address);  //복사 생성자

    char text[] = {'K', 'M', 'U', '\0'};  //문자열 리터럴과 달리 null 문자로 끝나는 char 배열
    string title(text);  //char 배열로 string 생성

    cout << "str : [" << str << "]\n";
    cout << "address : " << address << "\n";
    cout << "copyAddress : " << copyAddress << "\n";
    cout << "title : " << title << "\n";
    cout << "----------------------\n";

    // 2) string append/length
    str.append("I love ");
    str.append("Seoul.");
    cout << "str : [ " << str << " ]\n";
    cout << "str length : " << str.length() << "\n";
    cout << "----------------------\n";

    // 3) getline(cin >> ws, str)로 앞 공백 제거 후, 공백 포함 한줄 입력
    string line;
    cout << "Enter a line : ";
    getline(cin >> ws, line);  //앞 공백 제거 후, 공백 포함 한줄 입력
    cout << "line : [ " << line << " ]\n";
    cout << "----------------------\n";

    // 4) stoi(str)로 문자열을 int로 변환
    string numStr;
    cout << "Enter a number : ";
    cin >> numStr;
    int num = stoi(numStr);  //문자열을 int로 변환
    cout << "numStr : " << numStr << ", num : " << num << "\n";
    
    return 0;
}