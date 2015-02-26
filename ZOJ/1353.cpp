#include  <stdio.h>

#define  LIMIT    760
long long dp[LIMIT][LIMIT];

int main()
{
	int n;
	for(int i=0;i<LIMIT;++i)
		dp[0][i]=1;
	for(int i=1;i<LIMIT;++i)
	{
		int j=i>>1;
		for(int k=i;k>j;--k)
			dp[i][k]=1;
		for(;j>=1;--j)
			dp[i][j]=dp[i][j+1]+dp[i-2*j][j];
		if(dp[i][1]<0)
			break;
	}
	while(scanf("%d",&n)!=EOF&&n)
		printf("%d %lld\n",n,dp[n][1]);
	return 0;
}