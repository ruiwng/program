#include  <stdio.h>
#include  <string.h>

char record[100000];
int primers[70000];
int main()
{
	memset(record,0,sizeof(record));
	int num=0;
	for(int i=2;i<100000;++i)
	{
		if(record[i]==0)
		{
			primers[num++]=i;
			for(int j=i<<1;j<100000;j+=i)
				record[j]=1;
		}
	}
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int index=1;
		int c=0;
		while(primers[index]<=n&&index<num)
		{
			if(primers[index]-primers[index-1]==2)
				++c;
			++index;
		}
		printf("%d\n",c);
	}
	return 0;
}