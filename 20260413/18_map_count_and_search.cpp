#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
/*
map으로 판매 횟수 집계하기
--------------------------
문제 상황
- 하루동안 팔린 상품 이름이 순서대로 기록되어 있다
- 가게 주인은 어떤 상품이 몇 번 팔렸는지 집계하고 싶다
- 또 특정 상품이 실제로 팔렸는지, 몇 번 팔렸는지도 확인하고 싶다

문제 설명
1) vector에 "판매된 상품 이름 목록"을 저장
2) map<string, int>로 각 상품이 몇 번 팔렸는지 집계한다.
3) find()로 특정 상품의 판매 횟수를 조회
*/

void printSales(const map<string,int>& salesCount){
    for(map<string,int>::const_iterator it=salesCount.begin();it!=salesCount.end();it++)
        cout << it->first << " : " << it->second << endl; 
}

void searchItem(const map<string,int>& salesCount, const string& title){
    map<string,int>::const_iterator it=salesCount.find(title);
    if(salesCount.find(title)!=salesCount.end())
        cout << "판매 기록 있음\n";
    else
        cout << "판매 기록 없음\n";
}


int main(){
    vector<string> soldItems;
    soldItems.push_back("apple");
    soldItems.push_back("banana");
    soldItems.push_back("apple");
    soldItems.push_back("mild");
    soldItems.push_back("apple");
    soldItems.push_back("banana");
    soldItems.push_back("apple");
    soldItems.push_back("apple");

    map<string, int> salesCount;

    // 판매 기록을 하나씩 보면서, 상품별 판매 횟수를 센다.
    for(vector<string>::iterator it=soldItems.begin();it!=soldItems.end();it++)
        salesCount[*it]++;
    
    // 집계 결과 출력
    printSales(salesCount);

    // 특정 상품의 판매 기록이 있는지 조회
    searchItem(salesCount, "apple");
    searchItem(salesCount, "orange");
    return 0;
}