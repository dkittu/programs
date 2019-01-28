
#include<stdio.h>

main()
{
    FILE *arr,*fp;
    int k[2][2];;
    arr =fopen("input.txt","r");
    int i,j;


    for(i=0 ;i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            fscanf(arr, "%d",&k[i][j]);

        }
    }

    /*for(i=0 ;i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d ",k[i][j]);

        }printf("\n");
    }*/


    float det=k[0][0]*k[1][1]-k[0][1]*k[1][0];
    printf("%.f",det);

    float mul[2][2];
    mul[0][0]=k[1][1];mul[0][1]=-k[0][1];mul[1][0]=-k[1][0];mul[1][1]=k[0][0];

    /*for(i=0 ;i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%.4f ",mul[i][j]);

        }printf("\n");
    }*/
    //printf("\n\n\n");
    float inverse[2][2];
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
    {
        inverse[i][j]=(mul[i][j])/det;
    }

    /*for(i=0 ;i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%.4f ",inverse[i][j]);

        }printf("\n");
    }*/
    fp=fopen("out.txt","w");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++)
    {
        fprintf(fp,"%.4f ",inverse[i][j]);
    }putc('\n',fp);
    }
                                   //fwrite(a[i], sizeof(float), 336, qfile);


    return 0;

}
