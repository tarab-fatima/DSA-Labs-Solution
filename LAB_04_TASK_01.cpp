#include <iostream>
#include "stack.h"
#include "stack.cpp"

using namespace std;

struct point
{
    int x;
    int y;
};

Stack<point> solve_maize(char maze [6][6],  point start , point dest)
{
    Stack<point> path(100);
    path.push(start);

    while(path.stackTop().x != dest.x || path.stackTop().y != dest.y)
    {
       
        if( start.y + 1 < 6 && maze[start.x][start.y+1] == ' ' )
        {
            maze[start.x][start.y] = '3';
            start.y = start.y + 1;
            path.push(start);
           
        }
        else if(start.x + 1 < 6 && maze[start.x+1][start.y] == ' ')
        {
            maze[start.x][start.y] = '3';
            start.x = start.x + 1;
            path.push(start);
        }
        else if(start.y - 1 >= 0 && maze[start.x][start.y-1] == ' ' )
        {
            maze[start.x][start.y] = '3';
            start.y = start.y - 1;
            path.push(start);
        }
        else if(start.x - 1 >= 0 &&  maze[start.x-1][start.y] == ' ' )
        {
            maze[start.x][start.y] = '3';
            start.x = start.x - 1;
            path.push(start);
        }
        else
        {
            maze[start.x][start.y] = '3';
            path.pop();

            if (path.isEmpty()) 
            {
                cout << "Unsolved"<< endl;
                break;
            }


            start = path.stackTop();
        }
    }
    
    


    
    return path;  
}


int main()
{

    char maze1[6][6] = { 
        {' ', '*', ' ', '*', ' ', ' '}, 
        {' ', '*', ' ', '*', ' ', ' '}, 
        {'P', ' ', ' ', ' ', '*', ' '}, 
        {'*', ' ', '*', '*', '*', ' '}, 
        {' ', ' ', ' ', ' ', '*', ' '}, 
        {'*', ' ', ' ', ' ', ' ', ' '} 
    };

     char maze2[6][6] = { 
    {' ', '*', ' ', '*', ' ', ' '}, 
    {' ', '*', ' ', '*', ' ', ' '}, 
    {'P', ' ', ' ', ' ', '*', ' '}, 
    {'*', '*', '*', '*', '*', ' '}, 
    {' ', ' ', ' ', ' ', '*', 'T'}, 
    {'*', ' ', ' ', ' ', ' ', ' '} 
    };

    Stack<point> sol1(100);
    Stack<point> sol2(100);

    point st = {2,0};
    point dt ={4,5};
    sol1 = solve_maize(maze1, st , dt);

     cout<<"The path is : "<<endl;
    while (!sol1.isEmpty()) 
    {
        point p = sol1.stackTop();
        sol1.pop();
        cout << "(" << p.x << "," << p.y << ") ";
    }

    cout<<endl;
    sol2 = solve_maize(maze2, st , dt);


   


    return 0;
}