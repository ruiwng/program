#include  <stdio.h>
#include  <queue>
#include  <vector>
#include  <functional>
using namespace std;

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		priority_queue<int,vector<int>,greater<int> > num_queue;
		for(unsigned int i=0;i<num;++i)
		{
			int number_temp;
			scanf("%d",&number_temp);
			num_queue.push(number_temp);
		}
		bool first_time=true;
		while(!num_queue.empty())
		{
			if(first_time)
				first_time=false;
			else
				printf(" ");
			printf("%d",num_queue.top());
			num_queue.pop();
		}
		printf("\n");
	}
}