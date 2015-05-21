#include  <stdio.h>
#include  <string.h>
int main()
{
	char ch[1001];
	int num[10];
	while(scanf("%s",ch)!=EOF)
	{
		 memset(num,0,sizeof(num));
		 char *p=ch;
		 while(*p!='\0')
		   ++num[*p++-'0'];
		 for(int i=0;i<10;++i)
		 {
			 if(num[i]!=0)
			   printf("%d:%d\n",i,num[i]);
		 }
	}
	return 0;
}
