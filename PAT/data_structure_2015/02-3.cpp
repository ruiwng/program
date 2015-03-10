#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
	int m,n,k;
	while(scanf("%d%d%d",&m,&n,&k)!=EOF)
	{
		for(int i=0;i<k;++i)
		{
			bool success=true;
			int max_num=0;
			stack<int> num_stack;
			for(int j=0;j<n;++j)
			{
				int temp;
				scanf("%d",&temp);
				if(success)
				{
					if(temp>max_num)
					{
						while(++max_num!=temp)
							num_stack.push(max_num);
						if(num_stack.size()>=m)
							success=false;
					}
					else if(temp<=max_num)
					{
						if(num_stack.empty()||num_stack.top()!=temp)
							success=false;
						else
							num_stack.pop();
					}
				}
			}
			if(success)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}