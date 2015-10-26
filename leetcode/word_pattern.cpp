#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

bool wordPattern(char* pattern, char* str) {
    char *record[26];
	for(int i = 0; i < 26; ++i)
		record[i] = NULL;

	char *p = pattern;
	char *q = str;
	while(*q == ' ')
		++q;
	char temp[1000];
	while(*p != '\0')
	{
		if(q == NULL)
			return false;
		int n = sscanf(q, "%s", temp);
		if(n != 1)
			return false;
		if(record[*p - 'a'] == NULL)
		{
			record[*p - 'a'] = (char *)malloc(strlen(temp) + 1);
			strcpy(record[*p - 'a'], temp);
		}
		else if(strcmp(record[*p - 'a'], temp) != 0)
			return false;
		++p;
		q = strchr(q, ' ');
		if(q != NULL)
			++q;
	}
	if(q != NULL && sscanf(q, "%s", temp) != 0)
		return false;
	for(int i = 0; i < 26; ++i)
	{
		if(record[i] == NULL)
			continue;
		for(int j = i + 1; j < 26; ++j)
		{
			if(record[j] != NULL && strcmp(record[i], record[j]) == 0)
				return false;
		}
	}
	return true;
}

int main()
{
	bool result = wordPattern("abba", "dog cat cat dog");
	result = wordPattern("abba", "dog cat cat fish");
	result = wordPattern("aaaa", "dog cat cat dog");
	result = wordPattern("abba", "dog dog dog dog");
	return 0;
}

