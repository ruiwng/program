#include  <stdio.h>
#include  <string.h>
#include  <algorithm>
using namespace std;

char tag[1200];

int primer_array[200];

int main()
{
	memset(tag,0,sizeof(tag));
	int index=0;
	primer_array[index++]=1;
	for(int i=2;i<1100;++i)
	{
		if(tag[i]==0)
		{
			primer_array[index++]=i;
			if(i>1000)
				break;
			int k=i<<1;
			for(;k<1100;k+=i)
				tag[k]=1;
		}
	}
	int n,c;
	while(scanf("%d%d",&n,&c)!=EOF)
	{
		int *higher=upper_bound(primer_array,primer_array+index,n);
		int num=higher-primer_array;
		printf("%d %d:",n,c);
		int start,end;
		if(num<c)
		{
			start=0;
			end=num-1;
		}
		else
		{
			start=((num-1)>>1)-c+1;
			end=(num>>1)+c-1;
		}
		for(int i=start;i<=end;++i)
			printf(" %d",primer_array[i]);
		printf("\n\n");
	}
	return 0;
}