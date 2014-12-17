#include  <stdio.h>
#include  <math.h>

int array[10];

int main()
{
	int num;
	while(scanf("%d",&num)!=EOF)
	{
		for(int i=0;i<10;++i)
		   array[i]=pow((double)i,num);
		int begin=pow(10.0,num-1),end=pow(10.0,num);
		for(int i=begin;i<end;++i)
		{
			int temp=i;
			int sum=0;
			for(int j=0;j<num;++j)
			{
				int n=temp%10;
				temp/=10;
				sum+=array[n];
			}
			if(sum==i)
				printf("%d\n",i);
		}
	}
	return 0;
}