#include  <stdio.h>
#include  <stack>
using namespace std;
typedef struct
{
	char ch;
	int next;
}NODE;
NODE node[100001];
int main()
{
	int begin[2];
	int num;
	stack<int> intStack[2];
	while(scanf("%d %d %d",&begin[0],&begin[1],&num)!=EOF)
	{
		for(int i=0;i<2;i++)
		{
			while(!intStack[i].empty())
				intStack[i].pop();
		}
		for(int i=0;i<num;i++)
		{
			int temp1;
			char temp2;
			int temp3;
			scanf("%d %c %d",&temp1,&temp2,&temp3);
			node[temp1].ch=temp2;
			node[temp1].next=temp3;
		}
		for(int i=0;i<2;i++)
		{
		  int current=begin[i];
		  while(current!=-1)
		  {
			  intStack[i].push(current);
			  current=node[current].next;
		  }
		  intStack[i].push(-1);
		}
		int start;
		while(intStack[0].top()==intStack[1].top())
		{
			start=intStack[0].top();
			intStack[0].pop();
			intStack[1].pop();
			if(intStack[0].empty()||intStack[1].empty())
				break;
		}
		if(start!=-1)
		   printf("%05d\n",start);
		else
			printf("-1\n");
	}
	return 0;
}