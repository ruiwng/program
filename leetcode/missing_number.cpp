int missingNumber(int* nums, int numsSize) {
	long long sum = (numsSize + 1) * numsSize >> 1;

	for(int i = 0; i < numsSize; ++i)
		sum -= nums[i];
	return sum;
}

int main()
{
	int num[] = {0, 1, 3};
	int result = missingNumber(num, 3);
	return 0;
}