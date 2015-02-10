#include  <stdio.h>
#include  <string.h>
#include  <math.h>

int main()
{
    char str[20];
	printf("Program 6 by team X\n");
    while(scanf("%s",str)!=EOF)
    {
        if(strcmp(str,"0000000000000000")==0||strcmp(str,"1000000000000000")==0)
        {
            printf(" 0.000000e+000\n");
            continue;
        }           
        bool negative=false;
        if(str[0]=='1')
            negative=true;
        int exponent=0;
        for(int i=1;i<8;++i)
            exponent=(exponent<<1)+str[i]-'0';
        double mantissa=1.0;
        double t=0.5;
        for(int i=8;i<16;++i)
        {
            if(str[i]=='1')
                mantissa+=t;
            t*=0.5;
        }
        double result=mantissa*pow(2.0,exponent-63);
        if(negative)
             printf("-");
        else
             printf(" ");

        if(result>=1.0)
        {
            int exp=0;
            while(result>=1.0)
            {
                 result/=10;
                 ++exp;
            }
            result*=10;
            --exp;
            printf("%.6fe+%03d\n",result,exp);
        }
        else
        {
            int exp=0;
            while(result<1.0)
            {
                result*=10;
                ++exp;
            }
             printf("%.6fe-%03d\n",result,exp);
         }      
    }
    printf("End of program 6 by team X");
    return 0;
}

