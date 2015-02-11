#include  <stdio.h>
#include  <string.h>

long long dp[501][501];
long long num[501];
int main()
{
	memset(dp,0,sizeof(dp));
	memset(num,0,sizeof(num));
    for(int i=1;i<=500;++i)
        dp[i][i]=1;
	for(int i=3;i<=500;++i)//i represent the number of blocks
	{
		for(int j=2;j<i;++j)//j indicates the blocks of the last column 
		{
			for(int k=1;k<=i-j&&k<j;++k)//if the blocks of last column is set, calculate the number of different staircases.
			{
				dp[i][j]+=dp[i-j][k];
			}
			num[i]+=dp[i][j];// num[i] indicates the sum of different staircases with i blocks
		}
	}
	int n;
	while(scanf("%d",&n)!=EOF&&n)
		printf("%lld\n",num[n]);
	return 0;
}
