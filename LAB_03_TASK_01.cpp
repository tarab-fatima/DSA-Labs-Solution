#include<iostream>
#include <cctype> 
#include "stack.h"
#include "stack.cpp"

using namespace std;



bool is_Palindrome_word(string palindrome)
{  
    
    Stack <char>palin(100);
    string cleaned="";
    
    for (int i = 0; i < palindrome.length(); i++) 
    {
        if (isalnum(palindrome[i])) 
        {
            char c = tolower(palindrome[i]);
            cleaned += c;
        }
    }
   
     int len = cleaned.length();
    for(int i=0 ; i<len/2; i++)
    {
        palin.push(cleaned[i]);
    }
    for(int j = (len % 2 == 0) ? (len / 2) : (len / 2 + 1) ; j<len ; j++)
	{
		if(palin.pop() != cleaned[j])
		{
			return false;
		}
        else
        {
            return true;
        }
	}

    
}



int main()
{
    string palin;
	getline(cin, palin);

    if(is_Palindrome_word(palin))
    {
        cout<<"It is a palindrome"<<endl;
    }
    else
    {
        cout<<"It is not a palindrome"<<endl;
    }
}