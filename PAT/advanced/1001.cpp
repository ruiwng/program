#include  <stdio.h>
#include  <stdlib.h>
#include  <stack>
using namespace std;
int main()
{
	int a,b;
	stack<int> intStack;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		while(!intStack.empty())
			intStack.pop();
		int c=a+b;
		int m;
		if(c<0)
		{
			printf("-");
			m=-c;
		}
		else
			m=c;
		if(m==0)
			intStack.push(0);
		else
		while(m!=0)
		{
			intStack.push(m%1000);
			m/=1000;
		}
		bool first=true;
		while(!intStack.empty())
		{
			if(first==true)
			{
				printf("%d",intStack.top());
				first=false;
			}
			else 
			   printf("%03d",intStack.top());
			intStack.pop();
			if(!intStack.empty())
				printf(",");
		}
		printf("\n");
	}
	return 0;
}