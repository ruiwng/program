#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int b[200000];
int main()
{
	memset(b,'\0',200000*sizeof(int));
	for(int i=2;i<100000;i++)
	{
		if(b[i]==0)
		{
			int j=200000/i;
			for(int k=2;k<=j;k++)
				b[k*i]=1;
		}
	}
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		int cnt1=0,cnt2=0;
		for(int i=2;i<200000;i++)
		{
			if(b[i]==0)
			{
				cnt1++;
				if(cnt1>=m&&cnt1<=n)
				{
					cnt2++;
					printf("%d",i);
					if(cnt2%10!=0&&cnt1!=n)
						printf(" ");
					if(cnt2>=10&&cnt2%10==0&&cnt1<n)
						printf("\n");
				}
				if(cnt1>n)
					break;
			}
		}
		printf("\n");
	}
	return 0;
}