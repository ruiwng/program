#include  <stdio.h>

int main()
{
	int year;
	while(scanf("%d",&year)!=EOF)
	{
		if(year>2000&&year<=2100)
		{
			for(int i=2004;i<=year&&i<2100;i+=4)
				printf("%d\n",i);
		}
		else
			printf("Invalid year!\n");
	}
	return 0;
}