#include <iostream>
#include <cstring> //strcmp

/*
1)  C-문자열 내용 비교는 std::strcmp(a, b)를 사용
    결과가 같으면 0, 다르면 양수/음수 (사전 순서에 따라)
*/

int main(){
    char correct[] = "program123";
    char input[50];

    std::cout << "PASSWORD : ";
    std::cin >> input;  // 공백 없는 입력으로 가정

    if(!(std::strcmp(input, correct)))
        std::cout << "Access Guaranteed.\n";
    else
        std::cout << "Access Denied.\n";

    return 0;
}