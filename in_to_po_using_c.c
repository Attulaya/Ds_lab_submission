#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
# define n 100
char stack[n];
int top=-1;

void push(char a)
{
    stack[++top]=a;
}

char pop()
{
    if (top==-1)
    {
        return -1;
    }
    
    return stack[top--];
}

int precedence(char ch)
{
switch(ch)
{
    case '(':
    case ')':
    case '#':return 1;
            break;
    case '+':
    case '-':return 2;
            break;
    case '*':
    case '/':return 3;
            break;
    case '^':return 4;
            break;
    default :break;
}
return 0;
}

int isOperator( char ch)
{
    switch (ch)
    {
    case '+':
    case '*':
    case '-':
    case '/':
    case '^':
    case ')':
    case '(': return 1;
        break;

        default:
            break;
            return 0;
    }
}
void in_to_po(char in[],char post[])
{
    int i,ch,j=0;
    stack[++top]='#';
    for(i=0;i<strlen(in);i++)
    {
        ch=in[i];

        if(!isOperator(ch))
        {
            post[j]=ch;
            j++;
        }
        else 
        {
            if(ch=='(')
            {
                push(ch);
            }
            else 
            {
                if(ch==')')
                {
                while (stack[top]!='(')
                {
                    post[j]=pop();
                    j++;
                }
                pop();
                }
                else
                { 
                    if(precedence(ch)>precedence(stack[top]))
                    {
                    push(ch);
                    }
                    else
                    {
                    while (precedence(ch)<=precedence(stack[top]))
                    {
                    post[j]=pop();
                    j++;
                    }
                    push(ch);
                    }
                }
            }
        }   
    }
    
    while (stack[top]!='#')
    {
        post[j]=pop();
        j++;
    }
    post[j]='\0';
}

int st[n];
int to= -1;

void push_in(int l)
{
    st[++to] = l;
}

char pop_in()
{
    if (to == -1)
    {
        return -1;
    }

    return st[to--];
}

int evaluate(char post[])
{
    char ch;
    int i=0,op1,op2;
    while ((ch=post[i++])!='\0')
    {
        if (isdigit(ch))
        {
            push_in(ch-'0');
        }
        else
        {
            op2=pop_in();
            op1=pop_in();
            switch (ch)
            {
            case '+':
                push_in(op1+op2);
                break;
            case '-':
                push_in(op1 - op2);
                break;
            case '*':
                push_in(op1 * op2);
                break;
            case '/':
                push_in(op1 / op2);
                break;
            case '^':
                push_in(pow(op1,op2));
                break;
            }
        }
        
    }
    return st[to];
}

int main()
{
    char infix[n],postfix[n];
    scanf("%s",infix);
    in_to_po(infix,postfix);
    printf("postfix expression is %s\n",postfix);
    printf("evaluated postfix expression is %d\n", evaluate(postfix));
}
