#include  <stdio.h>
#include  <list>
#include  <algorithm>
using namespace std;

int main()
{
	string str;
	list<int> lst[2];
	unsigned int i=0;
	int temp;
	while(scanf("%d",&temp)!=EOF)
	{
		if(temp==-1)
		{
		   if(++i==1)
			   continue;
		   else
			   break;
		}
		lst[i].push_back(temp);
	}

	if(lst[0].empty()&&lst[1].empty())
	  printf("NULL\n");
	else
	{
		list<int> lst3(lst[0].size()+lst[1].size());
		merge(lst[0].begin(),lst[0].end(),lst[1].begin(),lst[1].end(),
			lst3.begin());
		printf("%d",*lst3.begin());
		for(list<int>::const_iterator iter=++lst3.begin();iter!=lst3.end();++iter)
		   printf(" %d",*iter);
		printf("\n");
	}
    return 0;
}