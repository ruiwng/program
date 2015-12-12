#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <algorithm>
using namespace std;

int main()
{
	char str1[110], str2[110];
	while(scanf("%s%s", str1, str2) != EOF)
	{
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		int len = max(len1, len2);
		char *result = (char *)malloc(len + 1);
		memset(result, '\0', len + 1);
		for(int i = 0; i < len; ++i)
		{
			int x = i < len1? (str1[len1 - 1 - i] - '0'):0;
			int y = i < len2? (str2[len2 - 1 - i] -'0'):0;
			if(i & 1)
			{
				int temp = y - x;
				if(temp < 0)
					temp += 10;
				result[len - 1 - i] = temp + '0';
			}
			else
			{
				int temp = x + y;
				temp %= 13;
				if(temp < 10)
					result[len - 1 - i] = temp + '0';
				else if( temp == 10)
					result[len - 1 - i] = 'J';
				else if(temp == 11)
					result[len - 1 - i] = 'Q';
				else if(temp == 12)
					result[len - 1 - i] = 'K';
			}
		}
		printf("%s\n", result);
		free(result);
	}
	return 0;
}