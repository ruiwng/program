#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int main()
{
	char ch[2][10002];
	int num[256];
	memset(num,'\0',256*sizeof(int));
	fgets(ch[0],10002,stdin);
	fgets(ch[1],10002,stdin);
	int n=strlen(ch[1]);
	for(int i=0;i<n;i++)
	   num[ch[1][i]]=1;
	n=strlen(ch[0]);
	for(int i=0;i<n;i++)
	{
		if(!num[ch[0][i]])
			printf("%c",ch[0][i]);
	}
	printf("\n");
	return 0;
}