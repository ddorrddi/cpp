#include <iostream>
#include <string>

using namespace std;

/*
모호성 사례
1) 오버로딩은 편리하지만, 후보가 둘 이상 똑같이 그럴듯하면 컴파일러도 결정에 어려움
2) 디폴트 매개변수는 호출함수를 늘리기 때문에 모호성을 만들기 쉬움
3) 자동 형 변환이 여러 방향으로 가능하면 의도하지 않은 충돌이 생김
4) 의미가 다른 함수는 이름을 분리하는 편이 안전
*/

namespace DefaultParamConflict{
    // 각각은 가능해보여도, 함께 두면 msg(10)같은 호출에 있어 충돌
    void msg(int id) { cout << "MSG : " << id << endl; }
    void msg(int id, string text = "") { cout << "MSG : " << id << " TEXT : " << text << endl; } // 디폴트 값이 있어 충돌
}

namespace CastAmbiguity{
    // value(3)에서는 int를 형변환 -> float/double로 모두 변환 가능 
    double square(double value) { return value * value; }
    float square(float value) { return value * value; }
}

namespace ReferenceAmbiguity{
    // add(a, b) -> 호출 문법이 같으면 컴파일러 입장에서도 구분 근거가 약함
    int add(int a, int b) { return a + b; }
    int add(int a, int &b) { b += a; return b; }    // REF는 공간(변수)을 받아야함
}

namespace BetterDesign{
    // 의미가 다른 함수는 이름을 나눠 두는 편이 더 분명
    int addValue(int a, int b) { return a + b; }
    int addInPlace(int a, int b) { b += a; return b; }
}

int main()
{
    DefaultParamConflict::msg(10, "GOOD"); // 명확
    // DefaultParamConflict::msg(10);      // 불명확
    
    cout << "SQUARE(3.0) = " << CastAmbiguity::square(3.0) << endl;     // double로 매핑
    // cout << "SQUARE(3.0) = " << CastAmbiguity::square(3) << endl;    // 매칭 에런
    
    int s = 10, t = 20;
    cout << "REFERENCE AMBIGUITY::add(10, 20) : " << ReferenceAmbiguity::add(10, 20) << endl;
    // cout << "REFERENCE AMBIGUITY::add(s, t) : " << ReferenceAmbiguity::add(s, t) << endl;       // 매칭 에러

    cout << "BETTER DESIGN::addValue(s, t) : " << BetterDesign::addValue(s, t) << endl;
    cout << "BETTER DESIGN::addInPlace(s, t) : " << BetterDesign::addInPlace(s, t) << endl;

    return 0;
}