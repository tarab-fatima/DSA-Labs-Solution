#include<iostream>
#include <cctype> 
#include "stack.h"
#include "stack.cpp"

using namespace std;


bool heterogeneousBracCheck( string in_fix)
{
    Stack <char>hetro_brac(100);
    int i=0;
    while(i< in_fix.length())
    {
        if ( in_fix[i]== '(' || in_fix[i]== '{'  || in_fix[i]== '[')  
        {  
            hetro_brac.push(in_fix[i]);  
        }  
        if ( in_fix[i]== ')' || in_fix[i]== '}'  || in_fix[i]== ']')  
        {  
            if (hetro_brac.isEmpty())  
            {
                    return 0;
            }
            char y = hetro_brac.pop();
            if ((in_fix[i] == ')' && y != '(') ||
                (in_fix[i] == '}' && y != '{') ||
                (in_fix[i] == ']' && y != '[')) 
            {
                return false;
            }
            
        }  
        
        i++;

    }
    return hetro_brac.isEmpty();

}


int main()
{
    string expr;

    cout << "Enter an infix expression: ";
    getline(cin, expr);

    if (heterogeneousBracCheck(expr))
    {
        cout << "GOOD";
    }
    else
    {
        cout << "BAD";
    }
    
    return 0;
}