#include  <stdio.h>
#include  <vector>
#include  <algorithm>
#include  <numeric>
using namespace std;

void func(const vector<int>& array,size_t begin,size_t end,vector<int>& satisfy,int& amount_sum,int pay_amount,int current_amount)
{
	if(begin==end)
		return;
	for(size_t i=begin;i<end;++i)
	{
		int temp_amount=current_amount-array[i];
		if(temp_amount<0)
			break;
		satisfy.push_back(array[i]);
		int previous_sum=amount_sum;
		amount_sum+=array[i];
		if(temp_amount>0)
		{
			func(array,i+1,end,satisfy,amount_sum,pay_amount,temp_amount);
			if(amount_sum==pay_amount)
				return;
			else
				while(satisfy.back()!=array[i])
					satisfy.pop_back();
			satisfy.pop_back();
			amount_sum=previous_sum;
		}
		else if(temp_amount==0)
			return;
	}
}
int main()
{
	unsigned int total_number;
	int amount_pay;
	while(scanf("%u %d",&total_number,&amount_pay)!=EOF)
	{
		vector<int> coin_array(total_number);
		for(unsigned int i=0;i<total_number;++i)
			scanf("%d",&coin_array[i]);

		sort(coin_array.begin(),coin_array.end());

		vector<int> satisfy_array;
	    int amount_sum=0;
		int sum=accumulate(coin_array.begin(),coin_array.end(),0);
		if(sum>=amount_pay)
		    func(coin_array,0,coin_array.size(),satisfy_array,amount_sum,amount_pay,amount_pay);


		if(satisfy_array.empty())
			printf("No Solution\n");
		else
		{
			printf("%d",satisfy_array[0]);
			for(size_t i=1;i<satisfy_array.size();++i)
				printf(" %d",satisfy_array[i]);
			printf("\n");
		}
	}
}