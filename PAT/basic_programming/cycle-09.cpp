#include  <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int f=0;
		int y;
		for(;f<100;++f)
		{
			int temp=98*f-n;
			if(temp>=0&&temp%199==0)
			{
				y=temp/199;
				break;
			}
		}
		if(f==100)
			printf("No Solution\n");
		else
			printf("%d.%d\n",y,f);
	}
	return 0;
}