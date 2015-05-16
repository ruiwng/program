#include  <stdlib.h>

int compare(const void *a,const void *b)
{
	if(*((int*)a)<*(int*)b)
		return -1;
	else if(*((int*)a)>*(int*)b)
		return 1;
	else
		return 0;
}

int maximumGap(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),compare);
	int max_gap=0;
	for(int i=1;i<numsSize;++i)
	{
		if(nums[i]-nums[i-1]>max_gap)
			max_gap=nums[i]-nums[i-1];
	}
	return max_gap;
}

int main()
{

}