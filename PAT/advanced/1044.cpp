#include  <stdio.h>
#include  <vector>
using namespace std;

typedef struct
{
	unsigned int begin;
	unsigned int end; 
}diamond_pair;
int main()
{
	unsigned int total_number,amount;
	while(scanf("%u %u",&total_number,&amount)!=EOF)
	{
		vector<unsigned int> diamond_array(total_number);
		vector<diamond_pair> pair_array;
		for(unsigned int i=0;i<total_number;++i)
		{
			unsigned int diamond_temp;
			scanf("%u",&diamond_temp);
			diamond_array[i]=diamond_temp;
		}
		unsigned int current_amount=0;
		int prev_pos=-1;
		unsigned int prev_amount=0;
		for(unsigned int i=0;i<total_number;++i)
		{
			unsigned int amount_temp=prev_amount;
			for(unsigned int j=prev_pos+1;j<total_number;++j)
			{
				amount_temp+=diamond_array[j];
				if(amount_temp>=amount)
				{
					diamond_pair pair_temp;
					pair_temp.begin=i+1;
					pair_temp.end=j+1;
					prev_pos=j;
					prev_amount=amount_temp-diamond_array[i];
					while(prev_amount>=amount)
					{
						prev_amount-=diamond_array[prev_pos];
						prev_pos--;
					}
					if(current_amount==0||amount_temp<current_amount)
					{
						pair_array.clear();
						current_amount=amount_temp;
					}
					else if(amount_temp>current_amount)
						break;
					pair_array.push_back(pair_temp);
					break;
				}
			}
		}
		for(unsigned int i=0;i<pair_array.size();++i)
			printf("%u-%u\n",pair_array[i].begin,pair_array[i].end);

	}
	return 0;
}