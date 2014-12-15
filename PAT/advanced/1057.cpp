#include  <string.h>
#include  <stdio.h>
#include  <vector>
#include  <stack>
#include  <algorithm>
#include  <set>
using namespace std;

int main()
{
	int n;
	stack<int> stack_array;
	vector<int> result_array;
	multiset<int> sorted_array;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		multiset<int>::iterator iter_median=sorted_array.end();
	    int element_sum=0;
		for(int i=0;i<n;i++)
		{
			char ch[15];
			fgets(ch,15,stdin);
			if(strncmp(ch,"Pop",3)==0)
			{
				if(stack_array.empty())
					result_array.push_back(-1);
				else 
				{
					int temp=stack_array.top();
					result_array.push_back(temp);
					stack_array.pop();
					element_sum--;
					multiset<int>::iterator iter_temp=--sorted_array.upper_bound(temp);
					if(temp<*iter_median&&element_sum%2==1)
						++iter_median;
					else if(temp>*iter_median&&element_sum%2==0)
						--iter_median;
					else if(temp==*iter_median)
					{
						if(element_sum==0)
							iter_median=sorted_array.end();
						else if(iter_median!=iter_temp&&element_sum%2==0)
							--iter_median;
						else if(iter_median==iter_temp&&element_sum%2==1)
							++iter_median;
						else if(iter_median==iter_temp&&element_sum%2==0)
							--iter_median;
					}
					sorted_array.erase(iter_temp);
				}
			}
			else if(strncmp(ch,"Push",4)==0)
			{
				int x;
				sscanf(&ch[5],"%d",&x);
				stack_array.push(x);
				element_sum++;
				sorted_array.insert(x);
				if(iter_median==sorted_array.end())
					iter_median--;
				else if(x<*iter_median&&element_sum%2==0)
					--iter_median;
				else if(x>=*iter_median&&element_sum%2==1)
					++iter_median;
			}
			else if(strncmp(ch,"PeekMedian",10)==0)
			{
				if(iter_median==sorted_array.end())
					result_array.push_back(-1);
				else
				  result_array.push_back(*iter_median);
			}
		}
		for(vector<int>::const_iterator it=result_array.begin();it!=result_array.end();it++)
		{
			if(*it==-1)
				printf("Invalid\n");
			else
				printf("%d\n",*it);
		}
	}
	return 0;
}