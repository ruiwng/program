#include  <stdio.h>
#include  <string.h>

struct cash_info
{
	int num;
	int value;
};

cash_info cash_array[10];
int dp[100001];

int main()
{
	int cash,n;
	while(scanf("%d%d",&cash,&n)!=EOF)
	{
		
		for(int i=0;i<n;++i)
			scanf("%d%d",&cash_array[i].num,&cash_array[i].value);
		int max_value=0;
		if(cash!=0&&n!=0)
		{
			memset(dp,0,sizeof(dp));
			dp[0]=1;
			for(int i=0;i<n;++i)
			{
				for(int j=max_value;j>=0;--j)
				{
					if(dp[j])
						for(int k=1;k<=cash_array[i].num;++k)
						{
							int temp=j+k*cash_array[i].value;
							if(temp>cash)
								break;
							dp[temp]=1;
							if(temp>max_value)
								max_value=temp;
						}
				}
			}
		}
		printf("%d\n",max_value);
	}
	return 0;
}