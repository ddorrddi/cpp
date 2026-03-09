#include <iostream>
#include <limits>

/*
1)  'std::cin >> x'에서 숫자 대신 문제 (예: 'abc')를 입력하면 입력 실패
2)  실패 상태를 복구하지 않으면 다음에 나오는 'cin >> ...'에 대해 즉시 실패
3)  'clear()'는 실패 상태 풀고, 'ignore(..)'는 버퍼의 잘못된 입력을 버림
    --> 입력 실패 시 clear() + ignore()를 함께 처리
*/

int main(){
    int x = 0, y = 0;

    std::cout << "Enter an Integer : ";
    std::cin >> x;

    if (std::cin.fail()){
        std::cout << "[1] First read failed: not an integer.\n";
        // 복구 없이 다시 읽기 시도
        std::cout << "[2] Try reading again WITHOUT recovery...." << std::endl;
        std::cin >> y;
        if(std::cin.fail()){
            std::cout << "STILL FAILED\n";
        }
    }

    // 정상 복구: 상태 + 복구 함께 정리
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "[3] After clear() + ignore().... \n";
    std::cout << "Enter an integer : ";
    std::cin >> y;
    if(std::cin.fail()){
        std::cout << "*** FAILED AGAIN (input was still invalid) ***\n";
        return 0;
    }

    std::cout << "RECOVERED!!\n";
    std::cout << "YOUR ENTER : " << y << "\n";

    return 0;
}