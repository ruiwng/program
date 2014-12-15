#include  <stdio.h>

int main()
{
	int a;
	while(scanf("%d",&a)!=EOF)
	{
		if(a<0)
			printf("Invalid Value!\n");
		else if(a<=50)
		  printf("cost = %.2lf\n",0.53*a);
		else
		  printf("cost = %.2lf\n",0.53*50+0.58*(a-50));
	}
	return 0;
}