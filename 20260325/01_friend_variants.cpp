#include <iostream>
using namespace std;
/*  friend는 private 접근 권한을 외부에 부여
- 외부 함수 friend는 해당 외부함수만 접근 가능
- 외부 멤버 함수 friend는 해당 외부 멤버 함수만 접근 가능 
- 외부 클래스 friend는 해당 클래스의 모든 멤버가 접근 가능
--> 최소 권한 원칙 : 꼭 필요한 함수만 friend로 지정하는 것이 안전
*/

class Rect; // 전방 선언

bool equals(Rect r, Rect s); // 외부 함수 원형

class RectManager;

class RectManager{
public:
    bool equals(Rect r, Rect s);
    void copy(Rect& dest, Rect& src);
};

class Rect{
private:
    int width;
    int height;
public:
    // (1) 외부 함수 friend
    friend bool equals(Rect r, Rect s);
    // (2) 다른 클래스의 특정 멤버 함수 friend
    friend bool RectManager::equals(Rect r, Rect s);
    // (3) 다른 클래스 전체 friend
    friend class RectManager;

    Rect(int w, int h) : width(w), height(h) {}
};

bool equals(Rect r, Rect s){
    return (r.width == s.width && r.height == s.height);
}

bool RectManager::equals(Rect r, Rect s){
    return (r.width == s.width && r.height == s.height);
}

void RectManager::copy(Rect& dest, Rect& src){
    dest.width = src.width;
    dest.height = src.height;
}

int main(){
    Rect a(3, 4), b(4, 5), c(3, 4);
    RectManager man;

    cout << (equals(a, b) ? "equal\n" : "not equal\n");
    cout << (man.equals(a, c) ? "equal\n" : "not equal\n");

    man.copy(c, a);
    cout << "-------Copied--------" << endl;

    cout << (man.equals(a, c) ? "equal\n" : "not equal\n");
    
    return 0;
}