#include  <stdio.h>
#include  <string.h>

int main()
{
	char str[90];
	while(fgets(str,90,stdin)!=NULL)
	{
		unsigned int length=strlen(str);
		if(str[length-1]=='\n')
			str[length-1]='\0';
		char* p=str;
		char* q=strrchr(p,' ');
		int flag=1;
		while(q!=NULL)
		{
			if(flag==1)
				flag=0;
			else
				printf(" ");
			printf("%s",q+1);
			*q='\0';
			q=strrchr(p,' ');
		}
	    if(flag==0)
			printf(" ");
		printf("%s\n",p);
	}
	return 0;
}