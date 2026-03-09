#include <iostream>

/*
1)  namespace는 이름(함수/변수/클래스)의 "구역"을 만들어 이름 충돌을 줄임
2)  같은 이름 함수라도 'hohwi::print()', 'lee::print()'처럼 구분 호출 가능
3)  'using namespace ...'은 편하지만 여러 네임스페이스를 서끙면 이름 충돌로 모호성 에러가 날 수 있음
*/

namespace hohwi{
    void print(){
        std::cout << "hohwi::print()\n";
    }
}

namespace lee{
    void print(){
        std::cout << "lee::print()\n";
    }
}

int main(){
    hohwi::print();
    lee::print();

    using namespace hohwi;
    print(); //hohwi::print()가 호출

    return 0;
}