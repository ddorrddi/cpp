#include <iostream>

/*
1)  C-문자열 배열로 공백 포함 한 줄 입력받는 방법
'std::cin.getline(char배열, 크기)'는 공백 포함 한 줄을 읽고, 최대 '크기-1' 글자 + '\0' 저장
배열 크기를 넘는 긴 입력은 잘려 저장됨
*/

int main(){
    char name[10];

    std::cout << "Name?? ";
    std::cin.getline(name, 10);
    std::cout << "Your name is " << name << ".\n";

    return 0;
}