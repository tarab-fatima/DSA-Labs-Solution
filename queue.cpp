#include "queue.h"
#include <cstring>
#include <iostream>
using namespace std;

template <typename T>
Queue<T>::Queue(int c)
{
    this->capacity = c;
    this->data = new T[capacity];
    this->noOfElements = 0;
    front = 0;
    rear = 0;

}

template <typename T>
Queue<T>::Queue(const Queue& other)
{
    this->capacity = other.capacity;
    this->data = new T[other.capacity];
    this->noOfElements = other.noOfElements;
    memcpy(data, other.data, other.noOfElements * sizeof(T));
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] data;
}

template <typename T>
bool Queue<T>::isFull()
{
    return noOfElements == capacity;
}

template <typename T>
bool Queue<T>::isEmpty()
{
    return noOfElements == 0;
}

template <typename T>
void Queue<T>::enQueue(const T& d)
{
    if(!isFull())
    {
        this->data[rear] = d;
        rear = (rear + 1) %capacity;
        noOfElements ++;
    }
    else
    {
        cout << "Queue is full"<<endl;
    }
}

template <typename T>
T Queue<T>::deQueue()
{
    if(!isEmpty())
    {
        T e = data[front];
        front = (front + 1) %capacity;
        noOfElements --;
        return e;
    }
    else
    {
        cout << "Queue is empty"<<endl;
        return T();
    }
}

template <typename T>
int Queue<T>:: getNoOfElements()
{
    return noOfElements;
}

template <typename T>
T Queue<T>::queueFront()
{
    return data[front];
}

template <typename T>
int Queue<T>:: getFront()
{
    return front;
}

template <typename T>
int Queue<T>:: getRear()
{
    return rear;
}

template <typename T>
void Queue<T>:: display()
{
    cout<<"The value in queue are:"<<endl;

    for(int i = 0;i<noOfElements ;i++)
    {
        cout<<data[(i + front)% capacity]<<" ";
    }
    cout<<endl;
}

template <typename T>
void Queue<T>:: resize()
{
    T* data1 = new T [2*capacity];
    for(int i = 0;i<noOfElements ;i++)
    {
        data1[i] = this->data[(i + front)% capacity];
    }
    delete[]  data;
    this->data = data1;
    this->capacity = 2*capacity;
    this->front = 0;
    this->rear = noOfElements;

}


template <typename T>
Queue<T> Queue<T>::operator=(const Queue& other)
{
    if(this != &other)
    {
        delete[] data;
        this->capacity = other.capacity;
        this->data = new T[other.capacity];
        this->noOfElements = other.noOfElements;
        memcpy(data, other.data, other.top * sizeof(T));
    }
    return *this;
}
