#include  <stdio.h>
#include  <string.h>

int main()
{
	char str[5];
	fgets(str,5,stdin);
	int length=strlen(str);
	if(str[length-1]=='\n')
		str[length-1]='\0';

	--length;
	for(int i=length-1;i>=0;--i)
	{
		int number=str[length-1-i]-'0';
		if(i==2)
			for(int j=0;j<number;++j)
				printf("B");
		if(i==1)
			for(int j=0;j<number;++j)
				printf("S");
		if(i==0)
			for(int j=1;j<=number;++j)
				printf("%d",j);
	}
	printf("\n");
	return 0;
}