#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char** argv)
{
    printer(argv[1]);

    return 0;

}



int compare(const void *a, const void *b)
{
  return (*(char*)a - *(char*)b);
}
void swapper(char* left, char* right)
{
    char temp = *left;

    *left = *right;

    *right = temp;
}
void printer(char* yuyu)
{
    int slen = strlen(yuyu);
    qsort(yuyu, slen, sizeof(char), compare);
    int found = 1;
    do{
        printf("%s ", yuyu);
        int i;
        for (i = slen - 2; i >= 0 && yuyu[i] >= yuyu[i+1]; --i){}
        if (i > -1)
        {
            int j = i+1;
            int k;
            for(k=j;k<slen && yuyu[k];++k)
            {
                if (yuyu[k] > yuyu[i] && yuyu[k] < yuyu[j])
                    j = k;
            }

            swapper(&yuyu[i], &yuyu[j]);

            qsort(yuyu+i+1, slen-i-1, sizeof(char), compare);
        }
        else
        {
            found = 0;
        }
    }while(found);
}

