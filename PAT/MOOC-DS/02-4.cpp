#include  <stdio.h>
#include  <stack>
using namespace std;

int main()
{
	int m,n,k;
	while(scanf("%d%d%d",&m,&n,&k)!=EOF)
	{
		for(int i=0;i<k;++i)
		{
		    stack<int> num_stack;
			int max_value=0;
			bool success=true;
			for(int j=0;j<n;++j)
			{
				int temp;
				scanf("%d",&temp);
				if(success)
				{
					if(max_value<temp)
					{
						while(max_value<temp-1)
							num_stack.push(++max_value);
						max_value=temp;
						if(num_stack.size()>=m)
							success=false;
					}
					else if(!num_stack.empty()&&num_stack.top()==temp)
						num_stack.pop();
					else
						success=false;
				}
			}
			printf("%s\n",success?"YES":"NO");
		}
	}
	return 0;
}