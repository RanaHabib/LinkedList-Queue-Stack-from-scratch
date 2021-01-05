#pragma once

#include <iostream>

using namespace std;

template<class T>
class Queue {
private:
    T *data;
    int s;
public:
    Queue();

    Queue(T, int);

    ~Queue();

    T &front();

    T &back();

    void pop();

    void push(T);

    int size();

    bool empty();
};

template<class T>
Queue<T>::Queue() {
    s = 1;
    data = new T[s];
    data[0] = 0;
}

template<class T>
Queue<T>::Queue(T value, int init_size) {
    s = init_size;
    data = new T[s];
    for (int i = 0; i < s; i++) data[i] = value;
}

template<class T>
Queue<T>::~Queue() {
    s = 0;
    delete[] data;
}

template<class T>
T &Queue<T>::front() {
    return data[0];
}

template<class T>
T &Queue<T>::back() {
    return data[s - 1];
}

template<class T>
void Queue<T>::pop() {
    if (s > 0) {
        T *newData = new T[s - 1];
        for (int i = 1; i < s; i++) {
            newData[i - 1] = data[i];
        }
        delete data;
        data = newData;
        s--;
    }
}

template<class T>
void Queue<T>::push(T value) {
    s++;
    T *newData = new T[s];
    for (int i = 0; i < s - 1; i++) newData[i] = data[i];
    newData[s - 1] = value;
    delete data;
    data = newData;
}

template<class T>
int Queue<T>::size() {
    return s;
}

template<class T>
bool Queue<T>::empty() {
    return (s == 0);
}