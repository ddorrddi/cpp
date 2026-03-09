#include <iostream>

/*
1) 'std::cin'은 키보드 입력을 읽음
2) '>>' 공백/탭/줄바꿈을 구분자로 사용해서 값을 순서대로 변수에 저장
3) 'std::cin >> w >> h;'는 한줄 입력 ('3 4')도 되고, 여러 줄 입력도 가능 
*/

int main(){
    int w, h;

    std::cout << "Enter WIDTH and HEIGHT" << std::endl;
    std::cin >> w >> h;
    std::cout << "AREA = " << (w*h) << std::endl;

    return 0;
}