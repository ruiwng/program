#include  <stdlib.h>
#include  <stdio.h>

/*
bool canWinNim(int n) {
    if(n == 1 || n == 2 || n == 3)
		return true;
	int record[3];
	record[0] = record[1] = record[2] = 1;
	int index = 0;
	for(int i = 4; i <= INT_MAX; ++i)
	{
		if(record[0] == 0 || record[1] == 0 || record[2] == 0)
			record[index] = 1;
		else
			record[index] = 0;
		if(++index == 3)
			index = 0;
	}
	if(--index == -1)
		index = 2;
	return record[index] == 1;
}
*/

bool canWinNim(int n) {
    return n % 4 == 0? false : true;
}

int main()
{
	bool result = canWinNim(1348820612);
	return 0;
}