#include  <stdio.h>
#include  <string.h>
#include  <vector>
#include  <string>
#include  <queue>
#include  <unordered_map>
#include  <functional>
using namespace std;

struct node
{
	int frequence;
	node *left;
	node *right;
	node(int f=0,node *l=NULL,node *r=NULL):frequence(f),left(l),right(r){}
	bool operator>(const node& n) const
	{
		return this->frequence>n.frequence;
	}
};

struct node_cmp
{
	bool operator()(const node* lhs,const node* rhs) const
	{
		return *lhs>*rhs;
	}
};
int weight_num;

void get_weight(node *n,int depth)
{
	if(n->left==NULL&&n->right==NULL)
		weight_num+=n->frequence*depth;
	if(n->left!=NULL)
		get_weight(n->left,depth+1);
	if(n->right!=NULL)
		get_weight(n->right,depth+1);
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		priority_queue<node*,vector<node*>,node_cmp> node_queue;
		unordered_map<char,int> frequence_map;
		for(int i=0;i<n;++i)
		{
			char str[2];
			node *temp=new node;
			scanf("%s%d",str,&temp->frequence);
			frequence_map.insert(make_pair(str[0],temp->frequence));
			node_queue.push(temp);
		}
		while(node_queue.size()>1)
		{
			node *node1=node_queue.top();
			node_queue.pop();
			node *node2=node_queue.top();
			node_queue.pop();
			node_queue.push(new node(node1->frequence+node2->frequence,node1,node2));
		}
		node *head=node_queue.top();
		node_queue.pop();
		weight_num=0;
		get_weight(head,0);

		int m;
		scanf("%d",&m);
		char code[63][100];
		for(int i=0;i<m;++i)
		{
			int current_weight=0;
			bool success=true;
			for(int j=0;j<n;++j)
			{
				char str[2];
				scanf("%s%s",str,code[j]);
				int len=strlen(code[j]);
			    for(int k=0;k<j&&success;++k)
				{
					int len1=strlen(code[k]);
					if(strncmp(code[k],code[j],len1<=len?len1:len)==0)
						success=false;
				}
				if(success)
				   current_weight+=len*frequence_map[str[0]];
			}
			if(success&&current_weight==weight_num)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}