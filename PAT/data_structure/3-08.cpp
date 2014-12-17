#include  <stdio.h>
#include  <stack>
#include  <string>
using namespace std;

int main()
{
	unsigned int capacity_one,capacity_two;
	while(scanf("%u %u",&capacity_one,&capacity_two)!=EOF)
	{
		stack<int> stack_one,stack_two;
		char temp;
		getchar();
		while(scanf("%c",&temp))
		{
			if(temp=='T')
				break;
			if(temp=='A')
			{
				int temp_num;
				scanf("%d",&temp_num);
				if(stack_two.size()>=min(capacity_one,capacity_two)&&!stack_one.empty())
					printf("ERROR:Full\n");
				else if(stack_two.size()<min(capacity_one,capacity_two))
					stack_two.push(temp_num);
				if(stack_two.size()==min(capacity_one,capacity_two)&&stack_one.empty())
				{
					while(!stack_two.empty())
					{
						stack_one.push(stack_two.top());
						stack_two.pop();
					}
				}
			}
			if(temp=='D')
			{
				if(stack_one.empty())
				{
					while(!stack_two.empty()&&stack_one.size()<capacity_one)
					{
						stack_one.push(stack_two.top());
						stack_two.pop();
					}
				}
				if(stack_one.empty())
					printf("ERROR:Empty\n");
				else
				{
					printf("%d\n",stack_one.top());
					stack_one.pop();
				}
				if(stack_one.empty())
				{
					while(!stack_two.empty()&&stack_one.size()<capacity_one)
					{
						stack_one.push(stack_two.top());
						stack_two.pop();
					}
				}
			}
		}
	}
	return 0;
}