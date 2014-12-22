#include  <stdio.h>
#include  <string.h>
#include  <algorithm>
using namespace std;

int arry[13];
int tags[13];
int main()
{
	int n;
	int case_number=0;
	while(scanf("%d",&n)!=EOF&&n)
	{
		memset(arry,0,sizeof(arry));
		memset(tags,0,sizeof(tags));

		for(int i=0;i<n;++i)
			scanf("%d",&arry[i]);
		if(case_number++!=0)
			printf("\n");
		for(int i=6;i<n;++i)
			tags[i]=1;
		do
		{
			int num=0;
			for(int i=0;i<n;++i)
			{
				if(tags[i]==0)
					printf("%d%c",arry[i],++num==6?'\n':' ');
			}
		}while(next_permutation(tags,tags+n));
	}
	return 0;
}