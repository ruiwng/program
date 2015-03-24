#include  <string.h>
#include  <stdlib.h>

char *longestPalindrome(char *s) {
    char *str=(char*)malloc(1010);
	memset(str,0,1010);
	int length=0;
	char *p=s;
	while(*p!='\0')
	{
		char *m=p;
		char *n=p+1;
		int current_len;
		while(m>=s&&*n!='\0'&&*m==*n)
		{
			--m;
			++n;
		}
		current_len=n-m-1;
		if(current_len>length)
		{
			length=current_len;
			strncpy(str,m+1,length);
		}
		m=p-1;
		n=p+1;
		while(m>=s&&*n!='\0'&&*m==*n)
		{
			--m;
			++n;
		}
		current_len=n-m-1;
		if(current_len>length)
		{
			length=current_len;
			strncpy(str,m+1,length);
		}
		++p;
	}
	return str;
}

int main()
{
	char str[]="abccba";
	char *r=longestPalindrome(str);
	return 0;
}