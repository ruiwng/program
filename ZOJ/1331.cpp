#include  <stdio.h>
#include  <algorithm>
using namespace std;

struct sum_info
{
	int num1;
	int num2;
	int sum;
	bool operator<(const sum_info& s) const
	{
		return this->sum<s.sum;
	}
};

int one_sum[199];
sum_info two_sum[19900];

int main()
{
	for(int i=2;i<=200;++i)
		one_sum[i-2]=i*i*i;
	int index=0;
	for(int i=0;i<199;++i)
	{
		for(int j=i;j<199;++j)
		{
			two_sum[index].num1=i;
			two_sum[index].num2=j;
			two_sum[index].sum=one_sum[i]+one_sum[j];
			++index;
		}
	}
	sort(two_sum,two_sum+19900);
	for(int i=4;i<199;++i)
	{
		for(int j=0;j<i;++j)
		{
			if(one_sum[i]<3*one_sum[j])
				break;
			int temp=one_sum[i]-one_sum[j];
			int lower=0,upper=19899;
			int median;
			while(lower<=upper)
			{
				median=(lower+upper)>>1;
				if(two_sum[median].sum<temp)
				    lower=median+1;
				else if(two_sum[median].sum>temp)
					upper=median-1;
				else
					break;
			}
			if(lower<=upper)
			{
				while(median>0&&two_sum[median-1].sum==temp)
					--median;
				while(median<19900&&two_sum[median].sum==temp)
				{
					if(two_sum[median].num1>=j)
						printf("Cube = %d, Triple = (%d,%d,%d)\n",i+2,j+2,two_sum[median].num1+2,two_sum[median].num2+2);
					++median;
				}		
			}
				
		}
	}
	return 0;
}