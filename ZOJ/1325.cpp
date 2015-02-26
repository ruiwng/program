#include  <stdio.h>
#include  <string.h>

char mirror_array[260];

bool is_palindrome(char *p,int len)
{
	char *q=p+len-1;
	while(p<=q)
	{
		if(*p++!=*q--)
			return false;
	}
	return true;
}

bool is_mirrored(char *p,int len)
{
	char *q=p+len-1;
	while(p<=q)
	{
		if(mirror_array[*p++]!=*q--)
			return false;
	}
	return true;
}

const char *mirror1="AEHIJLMOSTUVWXYZ12358";
const char *mirror2="A3HILJMO2TUVWXY51SEZ8";
int main()
{
	char str[30];
	memset(mirror_array,0,sizeof(mirror_array));
	const char *p=mirror1;
	const char *q=mirror2;
	while(*p!='\0')
		mirror_array[*p++]=*q++;

	while(scanf("%s",str)!=EOF)
	{
		int len=strlen(str);
		bool palindrome=is_palindrome(str,len);
		bool mirrored=is_mirrored(str,len);
		printf("%s -- ",str);
		if(!palindrome&&!mirrored)
			printf("is not a palindrome.\n\n");
		else if(palindrome&&!mirrored)
			printf("is a regular palindrome.\n\n");
		else if(!palindrome&&mirrored)
			printf("is a mirrored string.\n\n");
		else
			printf("is a mirrored palindrome.\n\n");
	}
	return 0;
}