#include  <stdio.h>
#include  <stdlib.h>
#include  <stack>
using namespace std;
int main()
{
	unsigned long long a,b;
	int c;
	stack<int> intStack;
	while(scanf("%lld %lld %d",&a,&b,&c)!=EOF)
	{
		while(!intStack.empty())
		{
			intStack.pop();
		}
		unsigned long long m=a+b;
		do
		{
			intStack.push(m%c);
			m/=c;
		}while(m>=c);
		if(m!=0)
		    intStack.push(m);
		while(!intStack.empty())
		{
			printf("%d",intStack.top());
			intStack.pop();
		}
		printf("\n");
	}
	return 0;
}