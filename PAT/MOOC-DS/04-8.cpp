#include  <stdio.h>
#include  <math.h>
#include  <algorithm>
using namespace std;

int init_arry[1000];
int object_arry[1000];

void generate_tree(int start,int end,int pos)
{
	if(start>end)
		return;
	else if(start==end)
	{
		object_arry[pos]=init_arry[start];
		return;
	}
	int num=end-start+1;
	int i=2;
	int curr;
	while(true)
	{
		if(num-i<=i-1)
		{
			curr=start+i-1;
			break;
		}
		else if(num-i<=2*i-1)
		{
			curr=end-(i-1);
			break;
		}
		i<<=1;
	}
	object_arry[pos]=init_arry[curr];
	generate_tree(start,curr-1,(pos<<1)+1);
	generate_tree(curr+1,end,(pos<<1)+2);
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&init_arry[i]);
		sort(init_arry,init_arry+n);
		generate_tree(0,n-1,0);
		for(int i=0;i<n;++i)
			printf("%d%c",object_arry[i],i==n-1?'\n':' ');
	}
	return 0;
}