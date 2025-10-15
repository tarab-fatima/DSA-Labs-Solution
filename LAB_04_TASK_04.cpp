#include <iostream>
#include "queue.h"
#include "queue.cpp"

using namespace std;

struct point
{
    int index;
    int tickets;
};

int time_calculator(int ar[] ,int n , int k)
{
    Queue<point> index_ticket(50);

    for(int i = 0 ; i < n ; i++)
    {
        point t ;
        t.index= i;
        t.tickets = ar[i];
        index_ticket.enQueue(t);
    }

    int time_unit = 0;

    while(!index_ticket.isEmpty() )
    {
        point curr =index_ticket.deQueue();
       
        curr.tickets --;
        time_unit ++;

        if (curr.index == k && curr.tickets == 0  )
        {
            break ;
        }

        if (curr.tickets > 0)
        {
            index_ticket.enQueue(curr);
        }
           
       
        
    }


    return time_unit;

}



int main() 
{ 
    int arr[] ={3,5,3,7}; 
    int k = 3;
    int n= 4 ;
    int z = time_calculator(arr , n , k);
    cout<<"The time required for person with k th index , to buy all the tickets is "<<z;
    return 0;


} 