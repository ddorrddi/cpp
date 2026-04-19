#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
vector<string> + 사전순 비교
*/

int main()
{
    vector<string> sv;
    string name;

    cout << "5 names input" << endl;

    for(int i = 0; i < 5; i++){
        cout << i + 1 << " >> ";
        getline(cin, name);
        sv.push_back(name);
    }

    name = sv.at(0);

    for(int i = 0; i < sv.size(); i++)
        if(name < sv[i]) name = sv[i];

    cout << name << endl;

    return 0;
}