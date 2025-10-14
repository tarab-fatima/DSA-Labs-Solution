#include<iostream>
#include <cctype> 
#include "stack.h"
#include "stack.cpp"

using namespace std;

void addingLargeNumbers(const string op1 ,const string op2)
{
    Stack <int>opr_1(100);
    Stack <int>opr_2(100);
    Stack <int>result(100);

    int len_1 = op1.length();
    int len_2 = op2.length();

    for(int i=0 ;i < len_1 ; i++)
    {
        int c = op1[i];
        c -= 48;
        opr_1.push(c);

    }

    for(int i=0 ;i < len_2 ; i++)
    {
        int t = op2[i];
        t -= 48;
        opr_2.push(t);

    }

    int carry = 0;

    while( !opr_1.isEmpty() || !opr_2.isEmpty() )
    {
        if (!opr_1.isEmpty())
        {
            carry += opr_1.pop();
        } 
        if (!opr_2.isEmpty())
        {
            carry += opr_2.pop();
        } 


        if(carry > 9)
        {
            int x = (carry % 10);
            result.push(x);
            carry = carry/10;

        }
        else
        {
            result.push(carry);
            carry = 0;
        }

        


    }

    while(!result.isEmpty())
    {
        int x = result.pop();
        cout<<x;
    }
    cout<<endl;
    

}

int main()
{
    string operand1;
	getline(cin, operand1);

    string operand2;
	getline(cin, operand2);

    addingLargeNumbers(operand1 ,operand2);

    return 0;
}