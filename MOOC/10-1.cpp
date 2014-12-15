#include  <stdio.h>
#include  <string.h>

int main()
{
	char str[90];
	char ch[5];
	while(fgets(str,90,stdin)!=NULL)
	{
		fgets(ch,5,stdin);
		unsigned int length=strlen(str);
		if(str[length-1]=='\n')
		{
			str[length-1]='\0';
			--length;
		}
		char *p=str;
		char *q=p+length;
		for(;p<q;++p)
		{
			if(*p==ch[0])
				break;
		}
		if(p<q)
			printf("%s\n",p);
		else
			printf("Not found\n");
	}
	return 0;
}