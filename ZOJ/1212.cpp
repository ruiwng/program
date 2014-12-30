#include  <stdio.h>
#include  <string.h>
#include  <math.h>

#define  PI     3.14159265

int main()
{
    char str[200];
    printf("Problem 6 by team x\n");
    while(fgets(str,200,stdin)!=NULL)
    {
        char* p=str;
        while(*p==' ')
            ++p;
        double pipeline=0.0;
        double angle,dist;
        int index=0;
        double current_height=0.0;
        printf("\n");
        while(sscanf(p,"%lf%lf",&angle,&dist)==2)
        {
            current_height+=dist*sin(angle*PI/180);
            printf("Altitude of peak %d =%7.1lf\n",++index,current_height);
            pipeline+=dist*cos(angle*PI/180);
            p=strchr(p,' ');
            while(*p==' ')
                ++p;
            p=strchr(p,' ');
            while(*p==' ')
                ++p;
        }
        pipeline+=current_height/tan(-angle*PI/180);
        printf("Pipeline length    =%7.1lf\n",pipeline);
    }
    printf("End of problem 6 by team x\n");
    return 0;
}
