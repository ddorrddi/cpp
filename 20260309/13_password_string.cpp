#include <iostream>
#include <string>

/*
1)  std::string은 '=='으로 내용 비교 가능
*/

int main(){
    std::string correct = "program123";
    std::string input;

    std::cout << "PASSWORD : ";
    std::cin >> input;  // 공백 없는 입력으로 가정

    if(input == correct)
        std::cout << "Access Guaranteed.\n";
    else
        std::cout << "Access Denied.\n";

    return 0;
}