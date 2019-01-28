#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char s[100],ptn[100];
    strcpy(s,argv[1]);
    strcpy(ptn,argv[2]);
    int j,i=0;
    while(s[i]!='\0')
    {
        if(s[i]==ptn[0])
        {
            j=1;

            while( s[i+j]=='\0' && ptn[j]!='\0' || s[i+j]==ptn[j]){
                j++;
            if(ptn[j]=='\0')
                printf("%d ",i);}

        }
        i++;
    }
    return 0;
}
