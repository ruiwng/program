#include  <stdio.h>

char prime_array[1000000];

int main()
{
	prime_array[1]=1;
	for(unsigned int i=2;i<=1000000;++i)
	{
		if(prime_array[i]==1)
			continue;
		unsigned int j=i+i;
		while(j<=1000000)
		{
			prime_array[j]=1;
			j+=i;
		}
	}
	unsigned int num1,num2;
	scanf("%u %u",&num1,&num2);
	unsigned int index=0;
	unsigned int i=2;
	for(;i<=1000000;++i)
	{
		if(prime_array[i]==0)
			++index;
		if(index==num1)
			break;
	}
	int temp=0;
	int first=1;
	for(;i<=1000000;++i)
	{
		if(prime_array[i]==0)
		{
			if(first==1)
				first=0;
			else
				printf(" ");
			printf("%u",i);
			++index;
			++temp;
			if(temp==10)
			{
				printf("\n");
				first=1;
				temp=0;
			}
		}
		if(index==num2+1)
			break;
	}
	return 0;
}