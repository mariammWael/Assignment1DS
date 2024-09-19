
#include "Stackt.h"
#include <stdexcept>
#include <iostream>

using namespace std;


template <typename T>
Stackt<T>::Stackt(int size) : capacity(size), top(-1) {
    arr = new T[capacity];
}

template <typename T>
Stackt<T>::Stackt(const Stackt& other) : capacity(other.capacity), top(other.top) {
    arr = new T[capacity];
    for (int i = 0; i <= top; ++i) {
        arr[i] = other.arr[i];
    }
}

template <typename T>
Stackt<T>& Stackt<T>::operator=(const Stackt& other) {
    if (this == &other) {
        return *this;
    }


    delete[] arr;


    capacity = other.capacity;
    top = other.top;
    arr = new T[capacity];
    for (int i = 0; i <= top; ++i) {
        arr[i] = other.arr[i];
    }

    return *this;
}

template <typename T>
Stackt<T>::~Stackt() {

    delete[] arr;
}

template <typename T>
void Stackt<T>::push(T element) {
    if (isFull()) {
        throw overflow_error("Stack is full");
    }
    arr[++top] = element;
}

template <typename T>
T Stackt<T>::pop() {
    if (isEmpty()) {
        throw underflow_error("Stack is empty");
    }
    return arr[top--];
}

template <typename T>
T Stackt<T>::peek() const {
    if (isEmpty()) {
        throw underflow_error("Stack is empty");
    }
    return arr[top];
}

template <typename T>
bool Stackt<T>::isEmpty() const {
    return top == -1;
}

template <typename T>
bool Stackt<T>::isFull() const {
    return top == capacity - 1;
}

template <typename T>
void Stackt<T>::display() const {
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


template class Stackt<int>;
template class Stackt<char>;
template class Stackt<double>;
