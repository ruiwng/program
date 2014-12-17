/*
#include  <stdio.h>
#include  <vector>
#include  <math.h>

using namespace std;


int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		vector<char> num_array(num+1);
		unsigned int temp=sqrt(num);
		for(unsigned int i=2;i<=temp;++i)
		{
			if(num_array[i]==1)
				continue;
			unsigned int k=num/i;
			for(unsigned int j=2;j<=k;++j)
				num_array[j*i]=1;
		}
		unsigned int n=num/2;
		for(unsigned int i=2;i<=n;++i)
		{
			if(num_array[i]==0&&num_array[num-i]==0)
			{
				printf("%u = %u + %u\n",num,i,num-i);
				break;
			}
		}
	}
	return 0;
}*/

#include  <stdio.h>
#include  <math.h>

bool is_prime(unsigned int num)
{
	unsigned int temp=sqrt(static_cast<double>(num));
	unsigned int i;
	for(i=2;i<=temp;++i)
	{
		if(num%i==0)
			break;
	}
	if(i>temp)
		return true;
	else
		return false;
}
int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		unsigned int temp=num/2;
		for(unsigned int i=2;i<=temp;++i)
		{
			if(is_prime(i)&&is_prime(num-i))
			{
				printf("%u = %u + %u\n",num,i,num-i);
				break;
			}
		}
	}
	return 0;
}