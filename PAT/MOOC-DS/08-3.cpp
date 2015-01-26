#include  <stdio.h>
#include  <vector>
using namespace std;

struct node
{
	int number;
	bool known;
	node(int n):number(n),known(false){}
};

int main()
{
	int num;
	while(scanf("%d",&num)!=EOF)
	{
		vector<node> node_array;
		node_array.reserve(num);
		int exchange_count=num;
		for(int i=0;i<num;++i)
		{
			int n;
			scanf("%d",&n);
			node_array.push_back(node(n));
			if(node_array[i].number==i)
				--exchange_count;
		}

		int component=0;
		for(int i=0;i<num;++i)
		{
			int element_sum=0;
			int j=i;
			while(!node_array[j].known)
			{
				++element_sum;
				node_array[j].known=true;
				j=node_array[j].number;
			}
			if(element_sum>1)
				++component;
		}
		if(component==0)
			printf("0\n");
		else
		{
			if(node_array[0].number==0)
				printf("%d\n",exchange_count+component);
			else
				printf("%d\n",exchange_count+component-2);
		}
	}
	return 0;
}