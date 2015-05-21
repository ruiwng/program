#include  <stdio.h>
#include  <stack>
using namespace std;
int main()
{
	int a,b;
	int c;
	stack<int> intStack;
	while(scanf("%d %d %d",&a,&b,&c)!=EOF)
	{
		while(!intStack.empty())
			intStack.pop();
		int m=a+b;
		do
		{
			intStack.push(m%c);
			m/=c;
		}while(m!=0);
		while(!intStack.empty())
		{
			printf("%d",intStack.top());
			intStack.pop();
		}
		printf("\n");
	}
	return 0;
}
