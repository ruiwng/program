#include  <stdio.h>
#include  <vector>
#include  <queue>
using namespace std;

enum type
{
	 SUPPLIER_DISTRIBUTOR=0,
	 RETAILER
};

typedef struct
{
    double unit_price;
	type name;
	vector<unsigned int> child_array;
    double amount;
}node;

int main()
{
	unsigned int total_number;
	double unit_price,percentage;
	while(scanf("%u %lf %lf",&total_number,&unit_price,&percentage)!=EOF)
	{
		vector<node> chain_array(total_number);
		for(unsigned int i=0;i<total_number;++i)
		{
			unsigned int child_num;
			scanf("%u",&child_num);
			if(child_num>0)
			{
				chain_array[i].name=SUPPLIER_DISTRIBUTOR;
				chain_array[i].child_array.resize(child_num);
				for(unsigned int j=0;j<child_num;++j)
				    scanf("%u",&chain_array[i].child_array[j]);
			}
			else
			{
				chain_array[i].name=RETAILER;
				scanf("%lf",&chain_array[i].amount);
			}
		}
		chain_array[0].unit_price=unit_price;
		queue<unsigned int> q_array;
		q_array.push(0);

		double sales_sum=0;
		while(!q_array.empty())
		{
			unsigned int temp=q_array.front();
            q_array.pop();

			if(chain_array[temp].name==SUPPLIER_DISTRIBUTOR)
			{
			     double current_price=chain_array[temp].unit_price*(1+percentage/100);		
			    vector<unsigned int>& child_temp=chain_array[temp].child_array;			
			    for(unsigned int i=0;i<child_temp.size();++i)
			    {
				   chain_array[child_temp[i]].unit_price=current_price;
				   q_array.push(child_temp[i]);
			    }
		    }
			else
				sales_sum+=chain_array[temp].amount*chain_array[temp].unit_price;
		}
		printf("%.1lf\n",sales_sum);
	}
	return 0;
}