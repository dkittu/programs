

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *p1,*p2;
    char c;
    int wc=0,b1=0,l=0,al=0;

p1=fopen("input.txt","r");
p2=fopen("out.txt","w");
while(c=getc(p1)!=EOF)
{
    c=getc(p1);
    if(c=='\n')
    {

        l++;
        c=getc(p1);
        if(c=='\n')
        {
            b1++;
        }
        fseek(p1,-1,1);
    }
}
rewind(p1);
while(c=getc(p1)!=EOF)
{
    if(c!='\n'&&c!='\t'&&c!=' ')
    {

        c=getc(p1);
        if(c=='\n'||c=='\t'||c==' '||c==EOF)
        {
            wc++;
            if(c==EOF)
                break;
    }
}
}
rewind(p1);
while((c=getc(p1))!=EOF)
{

    if(isalpha(c))
        al++;
}
rewind(p1);
while((c=getc(p1))!=EOF)
{
    if(c!='\n'&&c!=' '&&c!='\t')
        putc(c,p2);
//printf("riir");
if(c=='\n')
{
    c=fgetc(p1);
    if(c!='\n')
    {
        putc('\n',p2);
    }
    fseek(p1,-1,1);
    if(c==EOF)
        break;
}
}
printf("%d\n%d\n%d",(l-b1+1+2),wc+2-5,al);
fclose(p1);
fclose(p2);
return 0;
}




