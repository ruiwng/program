#include  <stdio.h>
#include  <string.h>

char *p_end;

int func(char *p)
{
	if(*p=='0'||p>=p_end)
		return 0;
	if(*p>='1'&&*p<='9')
	{
		--*p;
		char* q=p+(*p-'0')+1;
		if(q>=p_end)
			q=p+1;
		return func(q)+1;
	}
	else
	{
		int temp=func(p+1);
		*p=temp%10+'0';
		return temp+1;
	}
}

int main()
{
	char str[25];
	while(scanf("%s",str)!=EOF)
	{
		if(strcmp(str,"ENDOFINPUT\n")==0)
			break;
		int len;
		scanf("%d",&len);
		while(scanf("%s",str))
		{
			if(strcmp(str,"END")==0)
				break;
			p_end=str+len;
			func(str);
			printf("%s\n",str);
		}
	}
	return 0;
}