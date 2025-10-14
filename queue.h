#ifndef QUEUE_ADT_TARAB
#define QUEUE_ADT_TARAB

template <typename T>
class Queue
{
    private:
        T* data;
        int noOfElements;
        int capacity;
        int front;
        int rear;

    public:
        Queue(int c);
        Queue(const Queue& other);
        ~Queue();
        bool isFull();
        bool isEmpty();
        void enQueue(const T& d);
        T deQueue();
        int getNoOfElements();
        T queueFront();
        int getFront();
        int getRear();
        void display();
        void resize();
        Queue operator=(const Queue& other);
};

#endif

