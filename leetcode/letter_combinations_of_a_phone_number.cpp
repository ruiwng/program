#include  <stdlib.h>
#include  <string.h>

int char_count[]={0,0,3,3,3,3,3,4,3,4};
char **result;
char *temp;
int row;
const char *str[]=
{
	"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
};

void generate_digits(char *p,int column)
{
	if(*p=='\0')
		strcpy(result[row++],temp);
	else
	{
		const char *t=str[*p-'0'];
		while(*t!='\0')
		{
			temp[column]=*t++;
			generate_digits(p+1,column+1);
		}
	}
}

char **letterCombinations(char *digits, int *returnSize) {
	if(digits==NULL||*digits=='\0')
	{
		*returnSize=0;
		return NULL;
	}
    char *p=digits;
	*returnSize=char_count[*p++-'0'];
	while(*p!='\0')
		*returnSize*=char_count[*p++-'0'];
	int len=p-digits;
	result=(char**)malloc(*returnSize*sizeof(char*));
	for(int i=0;i<*returnSize;++i)
	{
		result[i]=(char*)malloc(len+1);
		memset(result[i],0,len+1);
	}
	temp=(char*)malloc(len+1);
	memset(temp,0,len+1);
	row=0;
	generate_digits(digits,0);
	return result;
}

int main()
{
	int s;
	char **t=letterCombinations("23",&s);
	return 0;
}