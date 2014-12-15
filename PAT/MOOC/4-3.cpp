#include  <stdio.h>

char array[501];
int main()
{
	unsigned int num1,num2;
	array[1]=1;
	for(unsigned int i=2;i<251;++i)
	{
		if(array[i]==1)
			continue;
		for(unsigned int j=i+i;j<=500;j+=i)
			array[j]=1;
	}

	while(scanf("%u %u",&num1,&num2)!=EOF)
	{
		unsigned int count=0;
		unsigned int sum=0;
		for(unsigned int i=num1;i<=num2;++i)
		{
			if(array[i]==0)
			{
				count++;
				sum+=i;
			}
		}
		printf("%u %u\n",count,sum);
	}
}