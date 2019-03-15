#include  <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
	int *result = (int*)malloc(sizeof(int) * 2);
	for (int i = 0; i < numbersSize; ++i) {
		int x = target - numbers[i];
		int start = i + 1, end = numbersSize - 1;
		while (start <= end) {
			int middle = (start + end) >> 1;
			if (numbers[middle] == x)
			{
				result[0] = i + 1;
				result[1] = middle + 1;
				*returnSize = 2;
				return result;
			}
			else if (numbers[middle] < x)
				start = middle + 1;
			else
				end = middle - 1;
		}
	}
	*returnSize = 0;
	return NULL;
}

int main() {
	int numbers[] = {2, 7, 11, 15};
	int target = 9;
	int returnSize;
	int *result = twoSum(numbers, sizeof(numbers) / sizeof(int), target, &returnSize);
	return 0;
}