
int minSubArrayLen(int s, int* nums, int numsSize) {
	int min_length=0;
	int start=0,end=0;
	int sum=0;
	while(true)
	{
		while(end<numsSize&&sum<s)
			sum+=nums[end++];
		while(sum>=s)
		{
			if(min_length==0||end-start<min_length)
				min_length=end-start;
			sum-=nums[start++];
		}
		if(end==numsSize)
           break;
	}
	return min_length;
}

int main()
{
	int arry[5]={1,2,3,4,5};
	int length=minSubArrayLen(11,arry,5);
	return 0;
}