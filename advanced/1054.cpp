#include  <stdio.h>
#include  <stdlib.h>
#include  <map>
using namespace std;

int main()
{
	int M,N;
	map<int,int> map1;
	while(scanf("%d %d",&M,&N)!=EOF)
	{		
	    map1.clear();
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				int temp;
				scanf("%d",&temp);
				map1[temp]++;
			}
		}
		int max=0;
		int key=0;
		for(map<int,int>::iterator iter=map1.begin();iter!=map1.end();iter++)
		{
			if(iter->second>max)
			{
				key=iter->first;
				max=iter->second;
			}
		}
		printf("%d\n",key);
	}
	return 0;
}