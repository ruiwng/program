#include  <stdio.h>
#include  <vector>
using namespace std;


struct node
{
	unsigned int number;
	bool known;
	node():number(0),known(false){}
};

void DFT(vector<node>& array,unsigned int index,unsigned int& element_sum)
{
	array[index].known=true;
	element_sum++;
	unsigned int number_temp=array[index].number;
	if(!array[number_temp].known)
		DFT(array,number_temp,element_sum);
}

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		vector<node> node_array(num);
		unsigned int sum_num=num;
		bool zero_tag=false;
		for(unsigned int i=0;i<num;i++)
		{
			scanf("%u",&node_array[i].number);
			if(node_array[i].number==i)
			{
				sum_num--;
				if(i==0)
					zero_tag=true;
			}
		}

		unsigned int component=0;
		for(unsigned int i=0;i<=num;i++)
		{
			if(node_array[i].known)
				continue;
			unsigned int element_sum=0;
			DFT(node_array,i,element_sum);
			if(element_sum>1)
			    component++;
		}
		if(component==0)
			printf("0\n");
		else
		{
			if(!zero_tag)
		        printf("%u\n",sum_num+component-2);
			else
				printf("%u\n",sum_num+component);
		}
	}
}