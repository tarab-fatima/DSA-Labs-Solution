#include <iostream>
#include "stack.h"
#include "stack.cpp"

using namespace std;

string reverseWords(const string &str) 
{
    Stack<char> st(100);
	string rev_str ;
	

    for(int i=0 ; i< str.length() ; i++)
    {
        if(str[i]!=' ' && str[i]!='\0' )
        {
        	st.push(str[i]);
		}
		else
		{
			while(!st.isEmpty() )
		    {
		        rev_str+=st.pop();
		        
		    }
			rev_str += ' ';
		}
		
    }
    
	while (!st.isEmpty())
    {
        rev_str += st.pop();
    }
   
    return rev_str;

} 



int main()
{

    string str1="Welcome to DSA";
    string str2;
    str2=reverseWords(str1);
   
    cout<<str2<<endl;

    return 0;
}