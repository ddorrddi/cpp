#include <iostream>

using namespace std;

/*
템플릿 클래스 MyStack<T>
template <class T> class MyStack{...}
사용할 때 : MyStack<int> / MyStack<double>처럼 타입을 지정해야 함
*/

template <class T>

class MyStack{
private:
    int tos;
    T data[100];
public:
    MyStack() : tos(-1) {}
    void push(T element){
        if(tos == 99) { 
            cout << "STACK FULL" << endl; 
            return ; 
        }
        data[++tos] = element;
    }
    T pop() {
        if (tos == -1){
            T tmp;
            cout << "STACK EMPTY" << endl;
            return tmp;
        }
        return data[tos--];
    }
};

int main(){
    MyStack<int> iStack;
    iStack.push(3);
    cout << iStack.pop() << endl;

    MyStack<double> dStack;
    dStack.push(1.1);
    dStack.push(2.2);
    cout << dStack.pop() << endl;

    MyStack<char>* p = new MyStack<char>();
    p->push('a');
    p->push('b');
    cout << p->pop() << endl;
    delete p;

    return 0;
}