#include  <stdio.h>
#include  <math.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int limit=sqrt(static_cast<double>(n));
		int start;
		int length=0;
		int index=2;
		bool flag=false;
		while(index<=limit)
		{
			int current_length=0;
			int current_start=index;
			int temp=index;
			int product=n;
			while(product%temp==0)
			{
				flag=true;
			    product/=temp++;
				++current_length;
			}
			if(length<current_length)
			{
				length=current_length;
				start=current_start;
			}
			++index;
		}
		if(flag)
		{
		   printf("%d\n",length);
		   for(int i=0;i<length;++i)
			  printf("%d%c",start+i,i==length-1?'\n':'*');
		}
		else
			printf("1\n%d\n",n);
	}
	return 0;
}