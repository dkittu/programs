#include <stdio.h>
#include <stdlib.h>
int j;


struct stu{
int age,mark[5];

char name[100];
double avg;
}i;

int main()
{
   FILE *fp1, *res;
   res=fopen("out.txt","w");
   fp1= fopen("input.txt","r");
   while(!feof(fp1))
  {
      fscanf(fp1,"%s %d",i.name,&i.age);
      for(j=0;j<5;++j)
      {

          fscanf(fp1,"%d",&i.mark[j]);

          i.avg=i.avg+i.mark[j];
      }
      fprintf(res,"%s   %d\t%d\t%d\t%d\t%d\t%d\t%0.1f\n",i.name,i.age,i.mark[0],i.mark[1], i.mark[2],i.mark[3],i.mark[4],i.avg/5);i.avg=0;
  }
fclose(fp1);
fclose(res);
return 0;
}
