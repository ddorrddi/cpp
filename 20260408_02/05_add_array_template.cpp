#include <iostream>

using namespace std;

/*
T add(...)
*/

template <class T>

T add(T arr[], int size){
    T sum = 0;
    for(int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

int main()
{
    int x[] = {1, 2, 3, 4, 5};
    double y[] = {1.2, 3.4, 5.6, 7.8, 9.0};

    cout << add(x, 5) << endl;
    cout << add(y, 5) << endl;
}