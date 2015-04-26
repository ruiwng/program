#include <stdio.h>
#include <algorithm>
using namespace std;

long int arry[100000];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
			scanf("%ld",&arry[i]);
		sort(arry,arry+n);
		for(int i=0;i<n;++i)
			printf("%ld%c",arry[i],i==n-1?'\n':' ');
	}
	return 0;
}