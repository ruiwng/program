#include  <stdlib.h>
#include  <string.h>

int rob(int num[], int n) {
	if(n==0)
		return 0;
	if(n==1)
		return num[0];
    int *sum=(int*)malloc(n*sizeof(int));
	memset(sum,0,n*sizeof(int));
	for(int i=0;i<n;++i)
	{
		if(i>1)
			sum[i]=sum[i-2];
		if(i>2&&sum[i-3]>sum[i])
			sum[i]=sum[i-3];
		sum[i]+=num[i];
	}
	return sum[n-1]>sum[n-2]?sum[n-1]:sum[n-2];
}

int main()
{

}