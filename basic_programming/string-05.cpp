#include  <stdio.h>
#include  <string.h>
#include  <algorithm>
using namespace std;
int main()
{
	char str[110];
	fgets(str,110,stdin);
	unsigned int len=strlen(str);
	if(str[len-1]=='\n')
	   str[len-1]='\0';
	--len;
	unsigned int temp;
	scanf("%u",&temp);
	temp=temp%len;
	reverse(str,str+temp);
	reverse(str+temp,str+len);
	reverse(str,str+len);
	printf("%s\n",str);
	return 0;
}