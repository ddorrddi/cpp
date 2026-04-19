#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
map iterator로 전체 출력
- map<K,V> :: iterator it
- map도 begin(), end()를 통해 전체 순회가능
- it -> first (키), it -> second (값)
*/

void printMap(map<string, int>& m){
    for(map<string, int> :: iterator it=m.begin();it!=m.end();it++)
        cout << it->first << ": " << it->second << "won\n";
}

int main(){
    map<string, int> priceMap;
    priceMap["붕어빵"]=2000;
    priceMap["잉어빵"]=2500; 
    priceMap.insert(make_pair("국화빵",3000));

    printMap(priceMap);
    cout << "---------------------------\n";
    priceMap.erase("붕어빵");
    printMap(priceMap);
    return 0;
}