#include "stack.h"
#include <cstring>
#include <iostream>
using namespace std;

template <typename T>
Stack<T>::Stack(int c)
{
    this->capacity = c;
    this->data = new T[capacity];
    this->top = 0;

}

template <typename T>
Stack<T>::Stack(const Stack& other)
{
    this->capacity = other.capacity;
    this->data = new T[other.capacity];
    this->top = other.top;
    memcpy(data, other.data, other.top * sizeof(T));
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] data;
}

template <typename T>
bool Stack<T>::isFull()
{
    return top == capacity;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return top == 0;
}

template <typename T>
void Stack<T>::push(const T& d)
{
    if(!isFull())
    {
        this->data[top] = d;
        top++;
    }
    else
    {
        cout << "Stack is full"<<endl;
    }
}

template <typename T>
T Stack<T>::pop()
{
    if(!isEmpty())
    {
        top--;
        return data[top];
    }
    else
    {
        cout << "Stack is empty"<<endl;
        return T();
    }
}

template <typename T>
int Stack<T>::getTop()
{
    return top;
}

template <typename T>
T Stack<T>::stackTop()
{
    return data[top-1];
}

template <typename T>
Stack<T> Stack<T>::operator=(const Stack& other)
{
    if(this != &other)
    {
        delete[] data;
        this->capacity = other.capacity;
        this->data = new T[other.capacity];
        this->top = other.top;
        memcpy(data, other.data, other.top * sizeof(T));
    }
    return *this;
}

template <typename T>
void Stack<T>::  display()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Stack elements (top to bottom):" << endl;

    for (int i = top - 1; i >= 0; i--)
    {
        cout << data[i] << endl;
    }

}

