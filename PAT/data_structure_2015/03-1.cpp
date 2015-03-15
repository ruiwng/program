#include  <stdio.h>
#include  <string.h>
#include  <queue>
using namespace std;

struct node
{
	int left;
	int right;
	node():left(-1),right(-1){}
};

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int tags[10];	
		memset(tags,0,sizeof(tags));
		node node_array[10];
		for(int i=0;i<n;++i)
		{
			char str1[3],str2[3];
			scanf("%s%s",str1,str2);
			if(str1[0]!='-')
			{
				int l;
				sscanf(str1,"%d",&l);
				node_array[i].left=l;
				tags[l]=1;
			}
			if(str2[0]!='-')
			{
				int r;
				sscanf(str2,"%d",&r);
				node_array[i].right=r;
				tags[r]=1;
			}
		}
		int head;
		for(int i=0;i<n;++i)
		{
			if(tags[i]==0)
			{
				head=i;
				break;
			}
		}
		bool first=true;
		
		queue<int> node_queue;
		node_queue.push(head);
		while(!node_queue.empty())
		{
			int t=node_queue.front();
			node_queue.pop();
			if(node_array[t].left==-1&&node_array[t].right==-1)
			{
				if(first)
					first=false;
				else
					printf(" ");
				printf("%d",t);
			}
			if(node_array[t].left!=-1)
				node_queue.push(node_array[t].left);
			if(node_array[t].right!=-1)
				node_queue.push(node_array[t].right);
		}
		printf("\n");
	}
	return 0;
}
