#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int main()
{
	char ch[1001];
	int num[10];
	while(scanf("%s",ch)!=EOF)
	{
		 memset(num,'\0',10*sizeof(int));
	     int len=strlen(ch);
		 for(int i=0;i<len;i++)
		 {
			 num[ch[i]-'0']++;
		 }
		 for(int i=0;i<10;i++)
		 {
			 if(num[i]!=0)
			   printf("%d:%d\n",i,num[i]);
		 }
	}
	return 0;
}