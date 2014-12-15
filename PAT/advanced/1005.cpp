#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <stack>
using namespace std;
char number[10][10]=
{
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};
int main()
{
	char ch[101];
	stack<int> intStack;
	while(scanf("%s",ch)!=EOF)
	{
		while(!intStack.empty())
			intStack.pop();
		int n=strlen(ch);
		int sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=ch[i]-'0';
		}
		if(sum==0)
			intStack.push(0);
		else
		while(sum!=0)
		{
			intStack.push(sum%10);
			sum/=10;
		}
		while(!intStack.empty())
		{
			printf("%s",number[intStack.top()]);
			intStack.pop();
			if(!intStack.empty())
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}