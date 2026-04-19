#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
map으로 만든 영한 사전
1. map 기본
- map<K,V>는 key와 value를 한쌍으로 저장하는 컨테이너
- map 원소는 pair 구조이며, (key, value) 형태
- key는 중복 될 수 없고, key기준으로 자동 정렬
- 배열처럼 숫자인덱스로 위치를 찾는 것이 아니라, "이름표 역할의 key"로 값을 찾는다.
- 'map<string, string>' 이면 key와 value가 모두 string

2. map에서 자주보는 기본문법
- 'dic[key] = value' : 삽입 또는 수정 // 의도에 따라서 삽입, 수정 판단해야함 // 찾는 목적으로 쓸때는 위험
- 'dic.insert(make_pair(a, b))' : 삽입 표준 함수 // 의도가 확실하게 삽입인지 명로하게 알 수 있음
- 'dic.find(key)' : key가 있으면 iterator가 반환이 되고, 없으면 end()
- 'dic.size()' : 저장된 key-value 쌍의 개수
- 'dic.begin()', 'dic.end()' : 전체 원소 순회 범위를 지정 
*/

int main(){
    map<string, string> dic;

    // <영어, 뜻> 한쌍을 만들어 map에 저장
    dic.insert(make_pair("love", "사랑"));
    dic.insert(make_pair("apple", "사과"));

    // []는 pair 직접 만들지 않고, 삽입/ 수정 간단히 표현가능
    dic["cherry"] = "체리";

    cout << "The number of stored words: " << dic.size() << endl;
    
    //iterator로 map 전체를 순회하여 출력하는 코드 TODO
    for(map<string,string> :: iterator it=dic.begin();it!=dic.end();it++){
        cout << it->first << ": " << it->second << endl;
    }

    string eng;
    while(true){
        cout << "word search: ";
        getline(cin,eng);
        if(eng=="exit")
            break;
        if(dic.find(eng)==dic.end())
            cout << "NONE\n";
        else 
            cout << dic[eng] << endl;
    }

    cout << "Exit\n";
    return 0;
}