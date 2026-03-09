#include <iostream>

/*
1)  cpp 표준 라이브러리 이름 ( cout / endl ... 등)은 std 네임스페이스에 존재
2)  std 사용 방식 3가지
    - std::cout 처럼 접두사 사용 ( 귀찮지만 안전 )
    - using std::cout; 처럼 필요한 이름만 가져오기 ( 절충안 )
    - using namespace std; 전체를 가져오기 ( 편하지만 충돌 위험 )
*/

int main(){
    // 방법 1
    std::cout << "(1) using std:: prefix\n";
    
    // 방법 2
    using std::cout;
    using std::endl;
    cout << "(2) using selected namespace (cout, endl)" << endl;

    // 방법 3
    using namespace std;
    cout << "(3) using full namespace" << endl;

    return 0;
}