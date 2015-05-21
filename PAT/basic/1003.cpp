#include  <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		char str[110];
		while(n--!=0)
		{
			int a_left=0,a_center=0,a_right=0;
			scanf("%s",str);
			char *p=str;
			while(*p=='A')
			{	
				++p;		
				++a_left;
			}
			if(*p++!='P')
			{
				printf("NO\n");
				continue;
			}
			while(*p=='A')
			{
				++p;
				++a_center;
			}
			if(*p++!='T')
			{
				printf("NO\n");
				continue;
			}
			while(*p=='A')
			{
				++p;
				++a_right;
			}
			if(*p!='\0')
			{
				printf("NO\n");
				continue;
			}
			printf("%s\n",a_center!=0&&a_left*a_center==a_right?"YES":"NO");	
		}
	}
	return 0;
}
