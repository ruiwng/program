#include  <stdio.h>
#include  <list>
#include  <algorithm>
#include  <iterator>
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
	
	list<int> lst3;
	set_intersection(lst[0].begin(),lst[0].end(),lst[1].begin(),lst[1].end(),
		back_inserter(lst3));
	if(lst3.empty())
		printf("NULL\n");
	else
	{
		printf("%d",*lst3.begin());
	    for(list<int>::const_iterator iter=++lst3.begin();iter!=lst3.end();++iter)
		  printf(" %d",*iter);
	    printf("\n");
	}
    return 0;
}