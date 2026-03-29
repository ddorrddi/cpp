#include <iostream>

/*
1)  'char name[10]'는 ㅗ치대 9글자 + 문자열 끝('\0')만 저장 가능
2)  'std::cin >> name'은 공백에서 입력이 끊김
    - Michael Jackson 입력 시, Michael만 저장이 됨
*/

int main(){
    char name[10];

    std::cout << "Name?? ";
    std::cin >> name; // 공백에서 입력이 끊김
    std::cout << "Your name is " << name << ".\n";
    return 0;
}