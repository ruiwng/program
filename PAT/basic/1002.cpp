#include  <stdio.h>
#include  <string.h>

char number[10][5]=
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
	char ch[110];
	while(scanf("%s",ch)!=EOF)
	{
		unsigned int len=strlen(ch);
		unsigned int sum=0;
		for(unsigned int i=0;i<len;i++)
			sum+=ch[i]-'0';
	    char temp[5];
		sprintf(temp,"%u",sum);
		unsigned int len_temp=strlen(temp);
		printf("%s",number[temp[0]-'0']);
		for(unsigned int i=1;i<len_temp;i++)
			printf(" %s",number[temp[i]-'0']);
		printf("\n");
	}
	return 0;
}