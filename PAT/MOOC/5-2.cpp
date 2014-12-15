#include  <stdio.h>
#include  <string.h>

char array[10][5]=
{
	"ling",
	"yi",
	"er",
	"san",
	"si",
	"wu",
	"liu",
	"qi",
	"ba",
	"jiu"
};

int main()
{
	char str[100];
	while(scanf("%s",str)!=EOF)
	{
		unsigned int len=strlen(str);
		unsigned int index=0;
		int first=1;
		if(str[index]=='-')
		{
			printf("fu");
			first=0;
			++index;
		}
		for(;index<len;++index)
		{
			if(first==1)
				first=0;
			else
				printf(" ");
			printf("%s",array[str[index]-'0']);
		}
		printf("\n");
	}
}