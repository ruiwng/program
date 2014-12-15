#include  <stdio.h>
#include  <stdlib.h>
#include  <stack>
#include  <vector>
using namespace std;
int main()
{
	unsigned int capacity;
	int maxNum,length;
	stack<int> intStack;
	vector<int> intVec;
	while(scanf("%u %d %d",&capacity,&maxNum,&length)!=EOF)
	{
		while(!intVec.empty())
			intVec.pop_back();
		for(int i=0;i<length;i++)
		{
			while(!intStack.empty())
				intStack.pop();
			bool possible=true;
			int currentMax=1;
			for(int j=0;j<maxNum;j++)
			{
				int temp;
				scanf("%d",&temp);
				if(possible)
				{
				   if(currentMax<=temp)
				   {
					for(int k=currentMax;k<=temp;k++)
					{
						intStack.push(k);
						if(intStack.size()>capacity)
						{
							possible=false;
						    break;
						}
					}
					if(possible)
					{
						currentMax=temp+1;
						intStack.pop();
					}
				   }
				   else
				   {
					   if(intStack.top()==temp)
						   intStack.pop();
					   else
						   possible=false;
				   }
				}
			}
			if(possible)
				intVec.push_back(1);
			else
				intVec.push_back(0);
		}
		for(vector<int>::const_iterator it=intVec.begin();it!=intVec.end();it++)
		{
			if(*it==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}