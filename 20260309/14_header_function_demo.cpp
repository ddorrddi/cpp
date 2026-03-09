#include <iostream>
#include <cmath>

/*
1)  'std::sqrt(x)'처럼 표준 수학 함수는 std 네임스페이스로 사용
*/

int main(){
    double x;

    std::cout << "Enter Number : ";
    std::cin >> x;

    std::cout << "sqrt(x) = " << std::sqrt(x) << "\n";

    return 0;
}