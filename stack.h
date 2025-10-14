#ifndef STACK_ADT_TARAB
#define STACK_ADT_TARAB

template <typename T>
class Stack
{
    private:
        T* data;
        int top;
        int capacity;

    public:
        Stack(int c);
        Stack(const Stack& other);
        ~Stack();
        bool isFull();
        bool isEmpty();
        void push(const T& d);
        T pop();
        int getTop();
        T stackTop();
        Stack operator=(const Stack& other);
        void display();

};

#endif

