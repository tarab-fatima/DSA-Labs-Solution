#include<iostream>
#include <cctype> 
#include "stack.h"
#include "stack.cpp"

using namespace std;

bool is_in_form(string ab)
{
    Stack <char> a(100);
    Stack <char> b(100);
    int len = ab.length();

    for(int i=0 ; i<len/2; i++)
    {
        char y = ab[i];
        if( y == 'a' )
        {
            a.push(ab[i]);
        }
        else
        {
            return false;
        }
        
    }
    for(int i=(len/2)  ; i<len; i++)
    {
        char y = ab[i];
        if( y == 'b' )
        {
            b.push(ab[i]);
        }
        else
        {
            return false;
        }
    }
    for(int i=0 ; i<len/2; i++)
    {
        a.pop();
        b.pop();
    }
    if(a.isEmpty() && b.isEmpty()) 
    {
        return true;
    }
    else
    {
        return false;
    }
    


}

int main()
{
    string x;
	getline(cin, x);

    if(is_in_form(x))
    {
        cout<<"It is in form a^n.b^n"<<endl;
    }
    else
    {
        cout<<"It is not in form a^n.b^n"<<endl;
    }

}