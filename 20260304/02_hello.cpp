#include <iostream>

int main() {
    std::cout << "Hello C++!" << std::endl;
    std::cout << "This program ends" << std::endl;
    return 0;
}

/*
cpp프로그램은 main()에서 시작
표준 출력은 std::out을 사용
줄바꿈은 '\n'이나 std::endl을 사용
but '\n'은 줄바꿈 문자만 출력하고 std::endl은 줄바꿈 후 flush까지 수행
return 0;은 프로그램 정상 종료의 의미
*/

/*
선택 가이드
일반 출력 ( 대부분 ) -> \n
입력 직전 안내처럼 "지금 당장 보여야 하는 출력" -> std::endl사용
*/