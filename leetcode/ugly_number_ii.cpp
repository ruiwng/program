#include  <stdio.h>
#include  <stdlib.h>

int nthUglyNumber(int n) {
	int *arry = (int *) malloc(sizeof(int) * n);
	arry[0] = 1;
	int index_2 = 0;
	int index_3 = 0;
	int index_5 = 0;
	int current_pos = 0;
	while(current_pos != n-1)
	{
		int value_2 = arry[index_2] * 2;
		int value_3 = arry[index_3] * 3;
		int value_5 = arry[index_5] * 5;

		if(value_2 <= value_3 && value_2 <= value_5)
		{
			arry[++current_pos] = value_2;
			++index_2;
			if(value_2 == value_3)
				++index_3;
			if(value_2 == value_5)
				++index_5;
		}
		else if(value_3 <= value_2 && value_3 <= value_5)
		{
			arry[++current_pos] = value_3;
			++index_3;
			if(value_3 == value_5)
				++index_5;
		}
		else if(value_5 <= value_2 && value_5 <= value_3)
		{
			arry[++current_pos] = value_5;
			++index_5;
		}
	}
	int result = arry[current_pos];
	free(arry);
	return result;
}

int main()
{
	int result = nthUglyNumber(10);
	return 0;
}