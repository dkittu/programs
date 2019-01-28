#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char stack[10];
int top = -1;
void push(char x)
{
    top++;
    stack[top] = x;
}

char pop()
{
    /*if(top == -1){
        printf("underflow\n");
        return -1;}
    else*/
        return stack[top--];
}

/*char strrrev(char a[10])
{
    int l=sizeof(a);int i;
    char aa[10];
    strcpy(aa,strrev(a));
    for(i=0;i<l;i++)
    {
        if(aa[i]=='(')
            aa[i]=')';
        else if(aa[i]==')')
            aa[i]='(';
    }
    return aa;
}*/



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
    char ptfx[10],prfx[10];
    char x;
    int i;int k=0;

    printf("Enter the expression :: ");
    scanf("%s",exp);
    //strcpy(exp,strrrev(realexp));
    strrev(exp);

    for(i=0;exp[i]!='\0';i++)
    {

        if(isalnum(exp[i]))
            prfx[k++]=exp[i];
        else if(exp[i] == ')')
            push(exp[i]);
        else if(exp[i] == '(')
        {
            while((x = pop()) != ')')
                prfx[k++]=x;
        }
        else
        {
            while(check(stack[top]) >= check(exp[i]))
                prfx[k++]=pop();
            push(exp[i]);
        }

    }
    while(top != -1)
    {
        prfx[k++]=pop();
    }
    prfx[k]='\0';
    strrev(prfx);
    puts(prfx);
}
