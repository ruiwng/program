#include  <string.h>
#include  <math.h>
#include  <stdio.h>

int countDigitOne(int n)
{
	if(n <= 0)
		return 0;
	char str[30];
	sprintf(str, "%d", n);
	int len = strlen(str);
	int left = 0, right = n;
	int sum = 0;
	for(int i = 0; i < len; ++i)
	{
		right -= (str[i]-'0') * (int)pow(10.0, len - i - 1);
		if(str[i] > '1')
			sum += (left + 1) * (int)pow(10.0, len - i - 1);
		else if(str[i] < '1')
			sum += left *(int)pow(10.0, len - i - 1);
		else
			sum += left *(int)pow(10.0, len - i - 1) + right + 1;
		left = left * 10 + str[i] - '0';
	}

	return sum;
}

int main()
{
	int result = countDigitOne(13);
	result = countDigitOne(1);
	result = countDigitOne(2);
	result = countDigitOne(9);
	result = countDigitOne(10);
	result = countDigitOne(11);
	result = countDigitOne(12);
	return 0;
}