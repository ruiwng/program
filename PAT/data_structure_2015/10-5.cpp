#include  <stdio.h>
#include  <vector>
using namespace std;

struct node
{
	int num;
	bool flag;
	node():num(0),flag(false){}
};
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		vector<node> node_array(n);
		for(int i=0;i<n;++i)
			scanf("%d",&node_array[i].num);
		int exchange_num=0;
		for(int i=0;i<n;++i)
		{
			if(node_array[i].flag)
				continue;
			int j=i;
			int component=0;
			while(!node_array[j].flag)
			{
				++component;
				node_array[j].flag=true;
				j=node_array[j].num;
			}
			if(component!=1)
			{
				if(i==0)
					exchange_num+=component-1;
				else
					exchange_num+=component+1;
			}
		}
		printf("%d\n",exchange_num);
	}
	return 0;
}