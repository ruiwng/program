#include  <stdio.h>
#include  <string.h>

int lengthOfLongestSubstring(char *s) {
	int length=0;
	char *p=s;
	int record[260];
	memset(record,0,sizeof(record));
	int current_length=0;
    while(*s!='\0')
	{
		if(++record[*s]!=2)
			++current_length;
		else
		{
			while(*p!=*s)
			{
				--record[*p++];
				--current_length;
			}
			--record[*p++];
		}
		if(current_length>length)
			length=current_length;
		++s;
	}
	return length;
}

int main()
{
	char str[]="bbbbb";
	int len=lengthOfLongestSubstring(str);
	return 0;
}