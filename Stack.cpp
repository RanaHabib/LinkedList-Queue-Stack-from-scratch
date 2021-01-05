#include <iostream>
#include "stack.h"
using namespace std;
template<class T>
stack<T>::stack() {
    StackElements = new T[StackSize];
    for (int i = 0; i < StackSize; ++i) {
        StackElements[i] = 0;
    }
}

template<class T>
stack<T>::stack(T value, int InitialSize) {
    StackSize = InitialSize;
    StackElements = new T[InitialSize];
    for (int i = 0; i < InitialSize; ++i) {
        StackElements[i] = value;
    }
}

template<class T>
stack<T>::~stack() {
    delete [] StackElements;
}

template<class T>
int & stack<T>::top() {
    return StackElements[StackSize-1];
}

template<class T>
void stack<T>::pop() {
    StackSize--;
}

template<class T>
void stack<T>::push(T value) {
    T *tempStack = new T[StackSize+1];
    int i;
    for (i = 0; i < StackSize; ++i) {
        tempStack[i] = StackElements[i];
    }
    tempStack[i] = value;
    delete [] StackElements;
    StackElements = tempStack;
    StackSize++;
}

template<class T>
int stack<T>::size() {
    return StackSize;
}

template<class T>
void stack<T>::print() {
    for (int i = 0; i < StackSize; ++i) {
        cout<<StackElements[i]<<" ";
    }
    cout<<endl;
}



int main() {
    //testing default constructor
    stack<int> Stack;
    Stack.print();

    /////////////////////////////////////////////
    //testing parameterized constructor
    stack<int> ParamStack(1,4);
    ParamStack.print();

    /////////////////////////////////////////////
    //testing top function
    ParamStack.top() = 88;
    ParamStack.print();

    ////////////////////////////////////////////
    //testing pop function
    ParamStack.pop();
    ParamStack.print();

    //////////////////////////////////////////////
    //testing push function
    ParamStack.push(55);
    ParamStack.print();

    //////////////////////////////////////////////
    //testing size function
    cout<<"size: "<<ParamStack.size()<<endl;


    return 0;
}