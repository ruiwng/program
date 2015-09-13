#include  <stdio.h>
#include  <unordered_map>
using namespace std;

char str[10010];
const char *temp = "PATest";
int main()
{
	unordered_map<char, int> record_map;
	for(int i = 0; i < 6; ++i)
		record_map[temp[i]] = i;

	while(scanf("%s", str) != EOF)
	{
		char *p = str;
		int num_count[6] = {0};
		while(*p != '\0')
		{
			if(*p == 'P' || *p == 'A' || *p == 'T' || *p == 'e' || *p == 's' || *p == 't')
				++num_count[record_map[*p]];
			++p;
		}

		while(true)
		{
			bool flag = false;
			for(int i = 0; i < 6; ++i)
			{
				if(num_count[i] > 0)
				{
					flag = true;
					printf("%c", temp[i]);
					--num_count[i];
				}
			}
			if(!flag)
				break;
		}
		printf("\n");
	}
	return 0;
}