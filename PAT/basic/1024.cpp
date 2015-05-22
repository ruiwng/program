#include  <stdio.h>
#include  <string.h>

int main()
{
	char ch[10000];
	while(scanf("%s",ch)!=EOF)
	{
		if(ch[0]=='-')
			printf("-");
		char* p=strchr(ch,'E');
		*p++='\0';
		int m=strlen(ch);
		int n;
		sscanf(p,"%d",&n);
		if(n<0)
		{
			printf("0.");
			for(int i=n;i<-1;++i)
				printf("0");
			printf("%c",ch[1]);
			for(int i=3;i<=m;++i)
    			printf("%c",ch[i]);
		}
		else if(n>=0&&n<m-2)
		{
			printf("%c",ch[1]);
			for(int i=0;i<n;++i)
				printf("%c",ch[i+3]);
			printf(".");
			for(int i=3+n;i<=m;++i)
				printf("%c",ch[i]);
		}
		else
		{
			printf("%c",ch[1]);
			for(int i=3;i<=m;++i)
				printf("%c",ch[i]);
			for(int i=0;i<n-m+2;++i)
				printf("0");
		}
		printf("\n");
	}
	return 0;
}
