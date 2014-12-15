#include  <stdio.h>

int a[]={1,6,28,496,8128};
int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		for(int i=0;i<5;++i)
		{
			if(a[i]>=m&&a[i]<=n)
			{
				printf("%d = 1",a[i]);
				int temp=a[i]>>1;
				for(int j=2;j<=temp;++j)
				  if(a[i]%j==0)
					  printf(" + %d",j);
				printf("\n");
			}
		}
	}
	return 0;
}