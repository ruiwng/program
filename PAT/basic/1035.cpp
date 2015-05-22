#include  <stdio.h>
#include  <algorithm>
using namespace std;

int arr[2][100];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<2;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&arr[i][j]);

		int t=1;
		while(t<n&&arr[1][t]>=arr[1][t-1])
			++t;
		int m=t;
		while(m<n&&arr[1][m]==arr[0][m])
			++m;
		if(m==n)
		{
			printf("Insertion Sort\n");
			int temp=arr[1][t];
			int i=t-1;
			while(i>=0&&arr[1][i]>temp)
			{
				arr[1][i+1]=arr[1][i];
				--i;
			}
			arr[1][i+1]=temp;
			for(int i=0;i<n;++i)
			   printf("%d%c",arr[1][i],i==n-1?'\n':' ');
		}
		else
		{
			printf("Merge Sort\n");
			int i=1;
			int *start=arr[0];
			int *end=&arr[0][n];
			while(true)
			{
				int equal=true;
				for(int j=0;j<n;++j)
				{
					if(arr[0][j]!=arr[1][j])
					{
						equal=false;
						break;
					}
				}
				if(equal)
					break;
				int *p=start;
				int *end=p+n;
				while(p<end)
				{
					sort(p,min(p+i,end));
					p=p+i;
				}
				i<<=1;
			}
			while(start<end)
			{
				sort(start,min(start+i,end));
				start+=i;
			}
			for(int i=0;i<n;++i)
			   printf("%d%c",arr[0][i],i==n-1?'\n':' ');
		}
	}
	return 0;
}
