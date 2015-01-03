#include  <stdio.h>
#include  <math.h>

int main()
{
    double a,b,c;
    int triangle_number=0;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
    {
        if(a==0.0&&b==0.0&&c==0.0)
            break;
        printf("Triangle #%d\n",++triangle_number);
        if(a==-1)
        {
            if(b>=c)
                printf("Impossible.\n");
            else
                printf("a = %.3lf\n",sqrt(c*c-b*b));
        }
        else if(b==-1)
        {
            if(a>=c)
                printf("Impossible.\n");
            else
                printf("b = %.3lf\n",sqrt(c*c-a*a));
        }
        else if(c==-1)
            printf("c = %.3lf\n",sqrt(a*a+b*b));
        printf("\n");
    }
    return 0;
}
