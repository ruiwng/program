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
	char str[110];
	fgets(str,110,stdin);
	int length=strlen(str);
	if(str[length-1]=='\n')
		str[length-1]='\0';
	int sum=0;
	for(int i=0;i<length-1;++i)
	  sum+=str[i]-'0';

	char temp[10];
	sprintf(temp,"%d",sum);
	int first=1;
	length=strlen(temp);
	for(int i=0;i<length;++i)
	{
		if(first==1)
			first=0;
		else
			printf(" ");
		printf("%s",number[temp[i]-'0']);
	}
	printf("\n");
	return 0;
}