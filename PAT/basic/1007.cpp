#include  <stdio.h>

const int MAX_LENGTH=100000;

char arry[MAX_LENGTH];
int prime[50000];
int main()
{
	int n;
	int index=0;
	for(int i=2;i<MAX_LENGTH;++i)
	{
		if(arry[i]==0)
		{
			prime[index++]=i;
			int k=i<<1;
			for(;k<MAX_LENGTH;k+=i)
				arry[k]=1;
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		int number=0;
		for(int i=1;i<index;++i)
		{
			if(prime[i]>n)
				break;
			if(prime[i]-prime[i-1]==2)
				++number;
		}
		printf("%d\n",number);
	}
	return 0;
}