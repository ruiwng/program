#include  <stdio.h>
#include  <math.h>

int num_array[50];

int gcd(int a,int b)
{
	int temp;
	while(b!=0)
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}

int main()
{
	int num;
	while(scanf("%d",&num)!=EOF&&num)
	{
		for(int i=0;i<num;++i)
			scanf("%d",&num_array[i]);
		int n=0;
		for(int i=0;i<num-1;++i)
		{
			for(int j=i+1;j<num;++j)
			{
				if(gcd(num_array[i],num_array[j])==1)
					++n;
			}
		}
		if(n==0)
			printf("No estimate for this data set.\n");
		else
			printf("%.6lf\n",sqrt(6*(num*(num-1)/2)/static_cast<double>(n)));
	}
	return 0;
}