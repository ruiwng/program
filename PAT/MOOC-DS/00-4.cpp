#include  <stdio.h>
#include  <string.h>

int main()
{
	char str[30];
	while(scanf("%s",str)!=EOF)
	{
		int record[10];
		memset(record,0,sizeof(record));
		char *p=str;
		while(*p!='\0')
			++record[*p++-'0'];
		int carry=0;
		bool success=true;
		for(int i=strlen(str)-1;i>=0;--i)
		{
			int temp=((str[i]-'0')<<1)+carry;
			carry=temp/10;
			str[i]=temp%10+'0';
			if(--record[temp%10]==-1)
				success=false;
		}
		if(success&&carry==0)
			printf("Yes\n");
		else
		{
			printf("No\n");
			if(carry!=0)
				printf("%d",carry);
		}
		printf("%s\n",str);
	}
	return 0;
}