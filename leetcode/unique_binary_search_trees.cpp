#include  <stdlib.h>
#include  <string.h>

int numTrees(int n) {
    int *dp=(int*)malloc(sizeof(int)*(n+1));
	memset(dp,0,(n+1)*sizeof(int));
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;++i)
	{
		for(int j=0;j<=i-1;++j)
			dp[i]+=dp[j]*dp[i-1-j];
	}
	int result=dp[n];
	free(dp);
	return result;
}

int main()
{
	int n=numTrees(3);
	return 0;
}