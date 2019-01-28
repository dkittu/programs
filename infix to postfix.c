#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char stack[10];
int top = -1;
void push(char x)
{
    top++;
    stack[top] = x;
}

char pop()
{
    if(top == -1){
        printf("underflow\n");
        return -1;}
    else
        return stack[top--];
}

int check(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

 void main()
{
    char exp[10];
    char x;
    int i;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    for(i=0;exp[i]!='\0';i++)
    {

        if(isalnum(exp[i]))
            printf("%c",exp[i]);
        else if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(check(stack[top]) >= check(exp[i]))
                printf("%c",pop());
            push(exp[i]);
        }

    }
    while(top != -1)
    {
        printf("%c",pop());
    }
}
