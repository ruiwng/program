#include  <stdio.h>
#include  <vector>
#include  <math.h>

using namespace std;

int main()
{
	unsigned int num1,num2;
	while(scanf("%u %u",&num1,&num2)!=EOF)
	{
		vector<char> num_array(num2+1);
		unsigned int temp=sqrt(num2);
		for(unsigned int i=2;i<=temp;++i)
		{
			if(num_array[i]==1)
				continue;
			unsigned int k=num2/i;
			for(unsigned int j=2;j<=k;++j)
				num_array[j*i]=1;
		}

		unsigned int count=0;
		unsigned int sum=0;
		if(num1<2)
			num1=2;
		for(unsigned int i=num1;i<=num2;++i)
		{
			if(num_array[i]==0)
			{
				count++;
				sum+=i;
			}
		}
		printf("%u %u\n",count,sum);
	}
	return 0;
}