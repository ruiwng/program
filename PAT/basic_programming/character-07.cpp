#include  <stdio.h>
#include  <string.h>

char str[500100];
int main()
{
	while(fgets(str,500100,stdin)!=NULL)
	{
		unsigned int length=strlen(str);
		if(str[length-1]=='\n')
			str[length-1]='\0';
		char* p_start=str;
		char* p_end=p_start+length-2;
		while(*p_end==' '&&p_end>=p_start)
		  p_end--;
		*(p_end+1)='\0';
		while(*p_start==' ')
			p_start++;
		char* p=p_end;
		while(p>p_start&&*p!=' ')
			--p;
		int first=1;
		while(p>p_start)
		{
			if(first==1)
				first=0;
			else
				printf(" ");
			printf("%s",p+1);
			while(*p==' '&&p>=p_start)
				--p;
			*(p+1)='\0';
			while(p!=p_start&&*p!=' ')
			--p;
		}
		if(first==0)
			printf(" ");
		printf("%s\n",p_start);
	}
	return 0;
}
