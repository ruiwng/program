#include  <stdio.h>
#include  <string.h>

int main()
{
	char str[90];
	while(fgets(str,90,stdin)!=NULL)
	{
		int length=strlen(str);
		if(str[length-1]=='\n')
		{
			str[length-1]='\0';
			--length;
		}
		for(int i=length-1;i>=0;--i)
			printf("%c",str[i]);
		printf("\n");
	}
	return 0;
}