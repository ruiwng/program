#include  <stdio.h>
#include  <stdlib.h>

bool is_beautiful(const char *str)
{
	int num[3] = {0};
	int index = 0;
	char ch[3];
	while(*str != '\0')
	{
		const char *p = str;
		ch[index] = *p;
		while(*str != '\0' && *str == *p)
		{
			++num[index];
			++str;
		}
		if(index == 0)
			++index;
		else if(index == 1)
		{
			if(ch[0] + 1 != ch[1] || num[0] < num[1])
			{
				ch[0] = ch[1];
				num[0] = num[1];
				num[1] = 0;
			}
			else
				++index;
		}
		else if(index == 2)
		{
			if(ch[1] + 1 == ch[2] && num[2] >= num[1])
				return true;
			else if(ch[1] + 1 == ch[2])
			{
				num[0] = num[1];
				num[1] = num[2];
				num[2] = 0;
				ch[0] = ch[1];
				ch[1] = ch[2];
			}
			else
			{
				num[0] = num[2];
				num[1] = num[2] = 0;
				index = 1;
			}
		}
	}
	return false;
}

char str[11000000];
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
		{
			int length;
			scanf("%d%s", &length, str);
			str[length] = '\0';
			printf("%s\n", is_beautiful(str)? "YES" : "NO");
		}
	}
	return 0;
}
