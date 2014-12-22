#include  <stdio.h>

const double PI=3.1415926535898;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			double x,y;
			scanf("%lf%lf",&x,&y);
			double square=PI*(x*x+y*y);
			printf("Property %d: This property will begin eroding in year %d.\n",i+1,static_cast<int>(square)/100+1);
		}
		printf("END OF OUTPUT.\n");
	}
	return 0;
}