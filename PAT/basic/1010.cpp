#include  <stdio.h>
#include  <string.h>

int main()
{
	char str[10000];
	while(fgets(str,10000,stdin)!=NULL)
	{
		char* p=str;
		int m,n;
		int flag=1;
		while(sscanf(p,"%d%d",&m,&n)==2)
		{
			if(n!=0)
			{
				if(flag)
					flag=0;
				else
					printf(" ");
				printf("%d %d",m*n,n-1);
			}
			while(*p==' ')
				++p;
			p=strchr(p,' ');
			while(*p==' ')
				++p;
			p=strchr(p,' ');
			if(p==NULL)
				break;
		}
		if(flag)
			printf("0 0");
		printf("\n");
	}
	return 0;
}