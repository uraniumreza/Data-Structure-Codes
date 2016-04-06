#include <bits/stdc++.h>
#include <iostream>

#define SIZE 1000

using namespace std;

class Stack{
    char *A;
    int tos;

public:
    Stack()
    {
        A = new char[SIZE];
        tos = -1;
    }

    void push(char ch)
    {
        tos++;
        if(tos==SIZE) cout<<"Stack Full"<<endl;
        else A[tos] = ch;
    }

    int pop()
    {
        if(tos==-1) cout<<"Stack is Empty"<<endl;
        char z = A[tos];
        tos--;
        return z;
    }
};

int main() {
    Stack s();

    s.push('(');
    cout<<s.pop()<<endl;

    return 0;
}