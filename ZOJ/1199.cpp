#include  <stdio.h>
#include  <math.h>

struct circle
{
    double x,y;
    double r;
    circle():x(0.0),y(0.0),r(0.0){
        
    }
    bool operator<(const circle& c) const
    {
        return this->r<c.r;
    }
};

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            circle c1,c2;
            scanf("%lf%lf%lf",&c1.x,&c1.y,&c1.r);
            scanf("%lf%lf%lf",&c2.x,&c2.y,&c2.r);
            if(c1<c2)
            {
                circle temp=c1;
                c1=c2;
                c2=temp;
            }
            double dist=sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y));
            if(dist<=c1.r-c2.r||c1.r==c2.r)
                printf("Impossible.\n");
            else
            {
                double x=(c1.r*c2.x-c2.r*c1.x)/(c1.r-c2.r);
                double y=(c1.r*c2.y-c2.r*c1.y)/(c1.r-c2.r);
                printf("%.2lf %.2lf\n",x,y);
            }
        }
    }
    return 0;
}
