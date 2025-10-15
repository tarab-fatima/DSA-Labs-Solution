#include <iostream>
#include "queue.h"
#include "queue.cpp"

using namespace std;

int main() 
{ 
    Queue<int> q(5); 
    
    q.enQueue(14); 
    q.enQueue(22); 
    q.enQueue(13); 
    q.enQueue(-6); 

    q.display(); 
    cout<<"Deleted Value = "<<q.deQueue()<<endl; 
    cout<<"Deleted Value = "<<q.deQueue()<<endl; 
    q.display(); 
    
    q.enQueue(9); 
    q.enQueue(20); 
    q.enQueue(5); 
    q.display(); 
    return 0;


} 