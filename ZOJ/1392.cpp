#include  <stdio.h>
#include  <string.h>

int main()
{
	char str[210];
	while(fgets(str,210,stdin)!=NULL)
	{
		if(strcmp(str,"ENDOFINPUT\n")==0)
			break;
		while(fgets(str,210,stdin)!=NULL)
		{
			if(strcmp(str,"END\n")==0)
				break;
			char *p=str;
			while(*p!='\n')
			{
				if(*p>='A'&&*p<='Z')
					printf("%c",'A'+(*p-'A'+21)%26);
				else
					printf("%c",*p);
				++p;
			}
			printf("\n");
		}
	}
	return 0;
}