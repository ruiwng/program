#include  <stdio.h>

int main()
{
	int num1,num2;
	while(scanf("%d %d",&num1,&num2)!=EOF)
	{
		unsigned int count=0;
		for(int i=num1;i<=num2;++i)
		{
			printf("%5d",i);
			if(++count==5)
			{
				printf("\n");
				count=0;
			}
		}
		if(count!=0)
			printf("\n");
		printf("Sum = %d\n",(num1+num2)*(num2-num1+1)/2);
	}
	return 0;
}