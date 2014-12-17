#include <stdio.h>
#include  <unordered_map>
using namespace std;

int main()
{
	unordered_map<int,unsigned int> integer_info;
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		for(unsigned int i=0;i<num;++i)
		{
			int temp;
			scanf("%d",&temp);
			integer_info[temp]++;
		}
		int max_integer;
		unsigned int count=0;
		for(unordered_map<int,unsigned int>::iterator iter=integer_info.begin();iter!=integer_info.end();
			++iter)
		{
			if(iter->second>count)
			{
				max_integer=iter->first;
				count=iter->second;
			}
		}
		printf("%d %u\n",max_integer,count);
	}
	return 0;
}