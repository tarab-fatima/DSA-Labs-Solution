#include <iostream>
#include "stack.h"
#include "stack.cpp"

using namespace std;

struct point
{
    int x;
    int y;
};

Stack<point> maize_sol(int maze [5][6],  point start , point dest)
{
    Stack<point> path(100);
    path.push(start);

    while(path.stackTop().x != dest.x || path.stackTop().y != dest.y)
    {
       
        if( start.y + 1 < 6 && maze[start.x][start.y+1] == 0)
        {
            maze[start.x][start.y] = 3;
            start.y = start.y + 1;
            path.push(start);
           
        }
        else if(start.x + 1 < 5 && maze[start.x+1][start.y] == 0)
        {
            maze[start.x][start.y] = 3;
            start.x = start.x + 1;
            path.push(start);
        }
        else if(start.y - 1 >= 0 && maze[start.x][start.y-1] == 0)
        {
            maze[start.x][start.y] = 3;
            start.y = start.y - 1;
            path.push(start);
        }
        else if(start.x - 1 >= 0 &&  maze[start.x-1][start.y] == 0)
        {
            maze[start.x][start.y] = 3;
            start.x = start.x - 1;
            path.push(start);
        }
        else
        {
            maze[start.x][start.y] = 3;
            path.pop();

            if (path.isEmpty()) 
            {
                cout << "No path found!\n";
                break;
            }


            start = path.stackTop();
        }
    }
    
    


    
    return path;  
}


int main()
{
    Stack<point> sol(100);
    int  maize[5][6]={{0,0,0,0,0,0},{1,0,1,1,1,0} , {0,0,0,0,0,0} ,{0,0,1,0,0,0} ,{0,1,1,0,0,0}};
    point st = {0,0};
    point dt ={4,3};
    sol=maize_sol(maize,st , dt);
   


    while (!sol.isEmpty()) {
    point p = sol.stackTop();
    sol.pop();
    cout << "(" << p.x << "," << p.y << ") ";
}


    return 0;
}