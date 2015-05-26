int rob_realize(int num[], int n) {
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

int rob(int* nums, int numsSize) {
    if(numsSize==0)
		return 0;
	if(numsSize==1)
		return nums[0];
    int a=rob_realize(nums,numsSize-1);
    int b=rob_realize(nums+1,numsSize-1);
    return a>=b?a:b;
}