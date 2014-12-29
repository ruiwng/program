#include  <stdio.h>

int main()
{
    int n;
    freopen("test.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        printf("INTERSECTING LINES OUTPUT\n");
        for(int i=0;i<n;++i)
        {
            double x1,y1,x2,y2,x3,y3,x4,y4;
            scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
            double a1=x2-x1;
            double b1=y2-y1;
            double c1=a1*y1-b1*x1;
            double a2=x4-x3;
            double b2=y4-y3;
            double c2=a2*y3-b2*x3;
            if(a1*b2==a2*b1)
            {
                if(a1*c2==a2*c1&&b1*c2==b2*c1)
                    printf("LINE\n");
                else
                    printf("NONE\n");
            }
            else
            {
                double x=(a1*c2-a2*c1)/(a2*b1-a1*b2);
                double y=(b1*c2-b2*c1)/(a2*b1-a1*b2);
                printf("POINT %.2lf %.2lf\n",x,y);
            }
        }
        printf("END OF OUTPUT\n");
        
    }
    return 0;
}
