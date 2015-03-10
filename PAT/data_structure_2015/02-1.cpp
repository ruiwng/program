#include  <stdio.h>
#include  <string.h>

int main()
{
	char str[10000];
	while(fgets(str,10000,stdin)!=NULL)
	{
		bool first=true;
		char *p=str;
		while(*p==' ')
			++p;
		int a,b;
		while(sscanf(p,"%d%d",&a,&b)==2)
		{
			a*=b;
			--b;
			if(a!=0)
			{
				if(first)
					first=false;
				else
					printf(" ");
				printf("%d %d",a,b);
			}
			p=strchr(p,' ');
			while(*p==' ')
				++p;
			p=strchr(p,' ');
			if(p==NULL)
				break;
			while(*p==' ')
				++p;
		}
		if(first)
			printf("0 0");
		printf("\n");
	}
	return 0;
}