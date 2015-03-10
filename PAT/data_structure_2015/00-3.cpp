#include  <stdio.h>
#include  <algorithm>
using namespace std;

int num[100];

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&num[i]);
		rotate(num,num+n-m%n,num+n);
		for(int i=0;i<n;++i)
			printf("%d%c",num[i],i==n-1?'\n':' ');
	}
	return 0;
}