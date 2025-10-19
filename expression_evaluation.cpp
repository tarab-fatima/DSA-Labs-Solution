#include<iostream>
#include <cctype> 
#include <cmath>
#include "stack.h"
#include "stack.cpp"

using namespace std;


int precedence(char op)
{
    if( op == '+' || op == '-')
    {
        return 1;
    }
    else if( op == '*' || op == '/' || op == '%')
    {
        return 2;
    }
    else if( op == '^' )
    {
        return 3;
    }
    else
    {
        return 0;
    }

}
    
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

bool homogeneousBracCheck( string in_fix)  
{
    Stack<char> homo_brac(100);
 
    int i=0;
    while(i < in_fix.length())  
    {  
         
        if ( in_fix[i]== '(' )  
        {  
            homo_brac.push(in_fix[i]);  
        }  
        if ( in_fix[i]== ')')  
        {  
            if (homo_brac.isEmpty())  
            {    
                return 0 ;
            }
            char y = homo_brac.pop();
            if (y != '(')   
            {  
                return 0 ; 
            }  
            
        }  
        i++;
    
    }  
    if (homo_brac.isEmpty()) 
    {
        return 1 ; 
    } 
    
    else 
    {
         return 0  ;
    } 
   
}

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

string infixToPostfix(const string& in_fix) 
{
    Stack<char> st(100);
    string postfix = "";
    int i = 0;
    while (i < in_fix.length()) 
    {
        char c = in_fix[i];
        if (isalnum(c)) 
        {
            postfix += c;
        } 
        else if (c == '(') 
        {
            st.push(c);
        } 
        else if (c == ')') 
        {
            while (!st.isEmpty() && st.stackTop() != '(') 
            {
                postfix += st.pop();
            }
            if (!st.isEmpty())
            { 
                st.pop();
            }
        } 
        else if (isOperator(c)) 
        {
            while (!st.isEmpty() &&
                   isOperator(st.stackTop()) &&
                   precedence(st.stackTop()) >= precedence(c)) 
            {
                postfix += st.pop();
            }
            st.push(c);
        }
        i++;
    }
    while (!st.isEmpty()) 
    {
        postfix += st.pop();
    }
    return postfix;
}

int perform_op(int a, int b, char op) 
{
    switch (op) 
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0; 
        case '%': return b != 0 ? a % b : 0;
        case '^': return pow(a, b); 
        default:  return 0;
    }
}

int postfix_evaluation(const string& postfix) 
{
    Stack<int> operand(100);
    int i = 0;
    while (i < postfix.length()) 
    {
        char c = postfix[i];

        if (isdigit(c)) 
        {
            operand.push(c - '0'); 
        }
        else if (isOperator(c)) 
        {
            int right = operand.pop();
            int left = operand.pop();
            int result = perform_op(left, right, c);
            operand.push(result);
        }
        i++;
    }
    return operand.pop();
}



int main()
{
    string expr;

    cout << "Enter an infix expression: ";
    getline(cin, expr);

    if (homogeneousBracCheck(expr))
        cout << "Homogeneous bracket check: VALID" << endl;
    else
        cout << "Homogeneous bracket check: INVALID" << endl;


    if (heterogeneousBracCheck(expr))
        cout << "Heterogeneous bracket check: VALID" << endl;
    else
        cout << "Heterogeneous bracket check: INVALID" << endl;


    string postfix = infixToPostfix(expr);
    cout << "Postfix expression: " << postfix << endl;
   
    cout<<"Evaluation of expression is"<<endl<<postfix_evaluation(infixToPostfix(expr))<<endl;
    
    return 0;
}

