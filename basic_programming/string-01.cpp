#include  <stdio.h>
#include  <string.h>

int main()
{
	char str[82];
	fgets(str,82,stdin);
	unsigned int len=strlen(str);
	if(str[len-1]=='\n')
		str[len-1]='\0';
	char temp;
	scanf("%c",&temp);
	char* p=strchr(str,temp);
	if(p==NULL)
		printf("Not found\n");
	else
		printf("%s\n",p);
	return 0;
}