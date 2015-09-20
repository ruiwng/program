int addDigits(int num) {
	while(num >= 10)
	{
		int temp = 0;
		while(num != 0)
		{
			temp += num % 10;
			num /= 10;
		}
		num = temp;
	}
	return num;
}

int main()
{
	int result = addDigits(38);
	return 0;
}