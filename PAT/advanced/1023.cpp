#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <stack>
using namespace std;
int main()
{
	char ch[21];
	int num[10];
	stack<int> intStack;
	while(scanf("%s",ch)!=EOF)
	{
		memset(num,'\0',10*sizeof(int));
		while(!intStack.empty())
			intStack.pop();
		int n=strlen(ch);
		for(int i=0;i<n;i++)
		{
			num[ch[i]-'0']++;
		}
		int x=0;
		for(int i=n-1;i>=0;i--)
		{
			int temp=(ch[i]-'0')*2+x;
			intStack.push(temp%10);
			num[temp%10]--;
			x=temp/10;
		}
		if(x!=0)
			intStack.push(x);
		int j;
		for(j=0;j<10;j++)
		{
			if(num[j]!=0)
				break;
		}
		if(j!=10)
			printf("No\n");
		else
			printf("Yes\n");
		while(!intStack.empty())
		{
			printf("%d",intStack.top());
			intStack.pop();
		}
		printf("\n");
	}
	return 0;
}