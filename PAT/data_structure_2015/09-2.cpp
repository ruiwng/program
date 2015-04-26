#include  <stdio.h>
#include  <algorithm>
using namespace std;

int arry[2][100];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&arry[0][i]);
		for(int i=0;i<n;++i)
			scanf("%d",&arry[1][i]);
		int index=1;
		while(index<n&&arry[1][index]>=arry[1][index-1])
			++index;
		int j=index;
		while(index<n&&arry[1][index]==arry[0][index])
			++index;
		if(index==n)
		{
			printf("Insertion Sort\n");
			int k=arry[1][j];
			int m=j-1;
			for(;m>=0&&arry[1][m]>k;--m)
				arry[1][m+1]=arry[1][m];
			arry[1][m+1]=k;
			for(int i=0;i<n;++i)
			   printf("%d%c",arry[1][i],i==n-1?'\n':' ');
		}
		else
		{
			bool flag=false;
			printf("Merge Sort\n");
			int step=2;
			while(true)
			{
				int start=0;
				while(true)
				{
					if(start+step<n)
					{
						sort(arry[0]+start,arry[0]+start+step);
						start+=step;
					}
					else
					{
						sort(arry[0]+start,arry[0]+n);
						break;
					}
				}
				if(flag)
					break;
				int x=0;
				for(;x<n;++x)
				{
					if(arry[0][x]!=arry[1][x])
						break;
				}
				if(x==n)
					flag=true;
				step<<=1;
			}
			for(int i=0;i<n;++i)
			   printf("%d%c",arry[0][i],i==n-1?'\n':' ');
		}
		
	}
	return 0;
}