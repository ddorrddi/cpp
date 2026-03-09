#include <iostream>
#include <string>

/*
1)  std::getline(std::cin, 변수)는 공백을 포함한 한 줄 전체를 읽음
    이름/문장/주소처럼 공백이 들어가는 입력은 getline이 기본 선택
2)  바로 앞에서 '>>'를 사용했다면 버퍼의 '\n'이 남아있어서 빈 문자열이 읽힐 수 있음
    igore로 버퍼를 먼저 정리
*/

int main(){
    std::string singer;

    std::cout << "Enter your favorite singer : ";
    std::getline(std::cin, singer);

    std::cout << "Favorite singer is " << singer << ".\n";

    return 0;
}