// header files
#include <stdio.h>
using namespace std;

// global variable
string stack[50];
int top = -1;

// function to push an element
void push(string s)
{
    stack[++top] = s;
}
// function to pop an element
string pop()
{
    return stack[top--];
}
// function to check if a character is operator or not
bool is_operator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

// Convert from postfix to Prefix
string convert(string exp)
{
    int i, l;
    l = exp.size();
    string op1, op2, tmp;
    // scanning the expression
    for (i = 0; i < l; i++)
    {
        // checking if the symbol is an operator
        if (is_operator(exp[i]))
        { // popping two operands from stack
            op1 = stack[top];
            pop();
            op2 = stack[top];
            pop();
            // concating the operands and operator
            tmp = exp[i] + op2 + op1;
            // Pushing string tmp into stack
            push(tmp);
        }
        // if the symbol is an operand
        else
        {
            // pushing the operand to the stack
            push(string(1, exp[i]));
        }
    }
    return stack[top];
}

// Driver Code
int main()
{
    string exp;
    printf("Enter the postfix expression: ");
    getline(cin, exp);
    printf("The prefix expression is: %s", convert(exp).c_str());
     
 return 0;
     
}