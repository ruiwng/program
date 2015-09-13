#include  <stdio.h>
#include  <string.h>

const char *str[] = 
{
	"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"
	, "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"
};

const char *str2[] = 
{
	"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"
};

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		char temp[100];
		fgets(temp, 100, stdin);
		for(int i = 0; i < n; ++i)
		{
			fgets(temp, 100, stdin);
			char *p = temp;
			while(*p == ' ')
				++p;
			if(*p >= '0' && *p <= '9')
			{
				int num;
				sscanf(p, "%d", &num);
				int x = num / 13;
				int y = num % 13;
				if(x != 0)
				{
					printf("%s", str2[x]);
					if(y != 0)
						printf(" %s", str[y]);
				}
				else
					printf("%s", str[y]);
				printf("\n");
			}
			else
			{
				char temp2[2][10];
				int r = sscanf(p, "%s%s", temp2[0], temp2[1]);
				int result = 0;
				for(int j = 0; j < r; ++j)
				{
					for(int k = 0; k < 26; ++k)
					{
						if(strcmp(str[k], temp2[j]) == 0)
						{
							if(k >= 13)
								result += (k - 12) * 13;
							else
								result += k;
						}
					}
				}
				printf("%d\n", result);
			}
		}
	}
	return 0;
}