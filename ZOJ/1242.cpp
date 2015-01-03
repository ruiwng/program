#include  <stdio.h>
#include  <math.h>

int main()
{
    double w,d;
    int sample_number=0;
    while(scanf("%lf%lf",&w,&d)!=EOF)
    {
        if(w==0&&d==0)
            break;
        int result=5730*log(d/w/810)/log(0.5);
        if(result<10000)
        {
            int temp=result%100;
            result=result/100*100;
            if(temp>=50)
                result+=100;
        }
        else if(result>10000)
        {
            int temp=result%1000;
            result=result/1000*1000;
            if(temp>=500)
                result+=1000;
        }
        printf("Sample #%d\n",++sample_number);
        printf("The approximate age is %d years.\n\n",result);
    }
    return 0;
}
