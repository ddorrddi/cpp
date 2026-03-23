#include <iostream>
#include <cstring>
using namespace std;

/*
얕은 복사 vs 깊은 복사 (포인터 멤버관리의 중요성)
문제 배경 : 
 - 객체가 포인터 멤버(동적메모리)를 가질 때, 복사 방식이 결과를 좌우
 - 디폴트 복사 생성자 : 얕은 복사 (포인트 값만 복사, 즉 같은 동적메모리 공유)
해결 방법 :
 - 깊은 복사 구현 (복사 생성자에서)
 - 동적 메모리를 멤버로 가지면 "복사 생성자" 구현하기
 */

class PersonShallow{
    char *name;
    int id;
public:
    PersonShallow(int id, const char *n) : id(id) {
        int len = strlen(n);
        name = new char[len + 1];
        strcpy(name, n);
    }
    ~PersonShallow() { delete[] name; }
    void changeName(const char* n){
        if (strlen(n) > strlen(name)) return;  // 메모리 부족 방지
        strcpy(name, n);
    }
    void show() { cout << "ID : " << id << ", Name : " << name << endl; }
};

class PersonDeep{
    char *name;
    int id;
public:
    PersonDeep(int id, const char *n) : id(id) {
        int len = strlen(n);
        name = new char[len + 1];
        strcpy(name, n);
    }
    PersonDeep(const PersonDeep &p) : id(p.id) {
        int len = strlen(p.name);
        name = new char[len + 1];
        strcpy(name, p.name);
    }
    ~PersonDeep() { delete[] name; }
    void changeName(const char* n){
        if (strlen(n) > strlen(name)) return;  // 메모리 부족 방지
        strcpy(name, n);
    }
    void show() { cout << "ID : " << id << ", Name : " << name << endl; }
};

int main(){
    // 얕은 복사: 같은 메모리 공유 → 이중 해제 문제 발생
    PersonShallow sf(1, "HOHWI");
    PersonShallow sd(sf);
    sd.changeName("HO");
    sf.show();  // 영향 받음
    sd.show();

    // 깊은 복사: 독립적인 메모리 → 안전
    PersonDeep df(2, "HOHWI");
    PersonDeep dd(df);
    dd.changeName("HO");
    df.show();  // 영향 없음
    dd.show();

    return 0;
}