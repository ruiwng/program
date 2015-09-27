#include  <stdio.h>
#include  <string.h>
#include  <algorithm>
using namespace std;

char str[1000010];
char str2[2000020];
int record[2000020];

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
		{
			scanf("%s", str);
			str2[0] = '#';
			char *p = str;
			char *q = str2 + 1;
			int len = 1;
			while(*p != '\0')
			{
				*q++ = *p++;
				*q++ = '#';
				len += 2;
			}
			*(q-1) = '#';
			*q = '\0';
			record[0] = 0;
			record[1] = 1;
			int max_radis = 0;
			for(int j = 2 , k = 0; j < len; )
			{
				while(j - k - 1 >= 0 && j + k + 1 < len && str2[j - k - 1] == str2[j + k + 1]) 
					++k;
				record[j] = k;
				if(record[j] > max_radis)
					max_radis = record[j];
				int m = 1;
				for(; m <= k && record[j] - m != record[j - m]; ++m)
				{
					record[j + m] = min(record[j] - m, record[j - m]);
					if(record[j + m] > max_radis)
						max_radis = record[j + m];
				}
				j += m;
				k = max(k - m , 0);
			}
			printf("%d\n", max_radis);
		}
	}
	return 0;
}