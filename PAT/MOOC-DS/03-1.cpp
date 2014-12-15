#include  <stdio.h>

double a3,a2,a1,a0;

double func(double x)
{
    return ((a3*x+a2)*x+a1)*x+a0;
}

int main()
{

    while(scanf("%lf%lf%lf%lf",&a3,&a2,&a1,&a0)!=EOF)
    {
        double a,b;
        scanf("%lf%lf",&a,&b);
        double temp1=func(a);
        double temp2=func(b);
        if(temp1==0.0)
            printf("%.2lf\n",a);
        else if(temp2==0.0)
            printf("%.2lf\n",b);
        else
        {
            double result;
            while(true)
            {
                result=(a+b)/2;
                if(b-a<0.001)
                    break;
                double temp3=func(result);
                if(temp3==0.0)
                    break;
                else if(temp3*temp1<0)
                {
                    b=result;
                    temp2=temp3;
                }
                else
                {
                     a=result;
                     temp2=temp3;
                }
            }
            printf("%.2lf\n",result);
        }
    }
    return 0;
}
