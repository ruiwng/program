#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

char pattern[10010];
char str[1000010];

void generate_next(int next[])
{
	int j = 0;
	next[j++] = -1;
	int k = -1;
	while(pattern[j] != '\0')
	{
		while(k >= 0 && pattern[k + 1] != pattern[j])
			k = next[k];

		if(pattern[k + 1] == pattern[j])
			++k;
		next[j++] = k;
	}
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
		{
			scanf("%s%s", pattern, str);
			int len1 = strlen(pattern);
			int len2 = strlen(str);

			int *next = (int *) malloc(sizeof(int) * len1);
			generate_next(next);

			int num = 0;
			int q = -1;
			for(int j = 0; j < len2; ++j)
			{
				while(q >= 0 && str[j] != pattern[q + 1])
					q = next[q];
				if(str[j] == pattern[q + 1])
					++q;
				if(q == len1 - 1)
				{
					++num;
					q = next[q];
				}
			}
			printf("%d\n", num);
			free(next);
		}
	}
	return 0;
}