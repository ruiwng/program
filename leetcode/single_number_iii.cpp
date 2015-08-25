#include  <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
	int x = 0;
	for(int i = 0; i < numsSize; ++i)
		x ^= nums[i];
	int count = 0;
	while(!(x & 1))
	{
		x >>= 1;
		++count;
	}

	*returnSize = 2;
	int * result = (int *) malloc(sizeof(int) * 2);
	result[0] = result[1] = 0;
	x =  1 << count;
	for(int i = 0; i < numsSize; ++i)
	{
		if(nums[i] & x)
			result[0] ^= nums[i];
		else
			result[1] ^= nums[i];
	}
	return result;
}

int main()
{
	int nums[] = {1, 2, 1, 3, 2, 5};
	int size;
	int *result = singleNumber(nums, 6, &size);
	return 0;
}