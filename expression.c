#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float exp1(float);
float sin_x(float);
int main(int argc,char **argv)
{
    float y;
    y=atof(argv[1]);
    //float result=(sin_x(y)*sin_x(y)+exp1(y)*sin_x(y)+y*y+10);
    float result= (sin(y)*sin(y)+exp(y)*sin(y)+y*y+10);
    printf("%.9f",result);
    return 0;

}
