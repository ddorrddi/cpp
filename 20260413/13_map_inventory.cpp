#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
map<string, Item> 재고 관리 예제
-상품명으로 Item 정보를 찾는 구조
-erase(key)는 삭제를 할때 성공 여부를 0/1로 반환
*/

class Item{
public: 
    int price;
    int count;
    Item(int price =0, int count =0):price(price),count(count){}
};

int main(){
    map<string,Item> stock;
    while(true){
        cout << "상품 입고: 1, 검색: 2, 삭제: 3, 종료: 4 >> ";
        int menu;
        cin >> menu;

        string name;
        int price=0, count =0;
        switch(menu){
        case 1:
            cout << "상품명, 가격, 개수 입력 >> ";
            cin >> name >> price >> count;
            stock.insert(make_pair(name, Item(price,count)));
            break;
        case 2:
            cout << "상품명 입력 >> ";
            cin >> name;
            if(stock.find(name)==stock.end())
                cout << name << " 없음\n";
            else{
                Item item = stock[name];
                cout << "가격 = " << item.price << "원, 재고 = " << item.count << "개\n";
            }
            break;
        case 3:
        {
            cout << "상품명 입력 >> ";
            cin >> name;
            int removed = stock.erase(name);
            if(removed==0) cout << name << " 없음\n";
            else cout << name << " 삭제 완료ㅕ\n";
            break;
        } // 중괄호를 안하면 remove 선언에 대해서 보장이 안됨 case3를 뛰어 넘어서 case4로 가면 remove가 초기화가 안되고 넘어가기 때문에 컴파일러가 막아버림
        case 4:
            cout << "종료합니다..\n";
            return 0;
        }
    }
}