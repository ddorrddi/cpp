#include <iostream>
#include <string>
#include <limits>

/*
1)  std::string은 C++표준문자열타입으로 길이를 자동관리해 char[]보다 다루기 쉬움
2)  실무 기본 문자열 입력은 std::string + string::getline의 조합
3)  다만 앞에서 '>>'를 쓰면, 엔터('\n')가 버퍼에 남아 다음 'getline'이 빈 문자열이 될 수 있음
4)  해결책 : std::cin.ignore(....., '\n');
    ---> 암기 : '>>'다음에 'getline'이면 'ignore' 한번
*/

int main(){
    int age;
    std::string intro;

    std::cout << "Enter age : ";
    std::cin >> age;

    // 버퍼에 남은 엔터 제거
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter an intro : ";
    std::getline(std::cin, intro);      // 공백 포함 한 줄 입력

    std::cout << "AGE = " << age << "\n";
    std::cout << "INTRO : " << intro << "\n";

    return 0;    
}