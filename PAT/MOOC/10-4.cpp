#include  <stdio.h>
#include  <string.h>

void reverse(char* p1,char* p2)
{
	while(p1<p2)
	{
		char temp=*p1;
		*p1=*p2;
		*p2=temp;
		++p1;
		--p2;
	}
}
int main()
{
	char str[110];
	while(fgets(str,110,stdin)!=NULL)
	{
		int N;
		scanf("%d",&N);
		getchar();
		int length=strlen(str);
		if(str[length-1]=='\n')
		{
			str[length-1]='\0';
			--length;
		}
		N%=length;
		char *p=str;
		reverse(p,p+N-1);
		reverse(p+N,p+length-1);
		reverse(p,p+length-1);
		printf("%s\n",p);
	}
	return 0;
}