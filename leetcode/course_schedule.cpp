#include  <stdio.h>
#include  <stdlib.h>

struct link_node
{
	int index;
	struct link_node *next;
};

struct node_info
{
	int traversed;
	struct link_node* adjacent_node;
};

bool finish;
struct node_info *node_arry;
struct link_node *link_arry;

void dfs(int index)
{
	struct link_node* p=node_arry[index].adjacent_node;
	node_arry[index].traversed=1;
	while(p!=NULL)
	{
		if(node_arry[p->index].traversed==0)
			dfs(p->index);
		else if(node_arry[p->index].traversed==1)
			finish=false;
		p=p->next;
	}
	node_arry[index].traversed=2;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize) {
    node_arry=(struct node_info*)malloc(numCourses*sizeof(struct node_info));
	link_arry=(struct link_node*)malloc(prerequisitesRowSize*sizeof(struct link_node));
	int index=0;
	for(int i=0;i<numCourses;++i)
	{
		node_arry[i].traversed=0;
		node_arry[i].adjacent_node=NULL;
	}
	for(int i=0;i<prerequisitesRowSize;++i)
	{
		struct link_node *p=&link_arry[index++];
		p->index=prerequisites[i][1];
		p->next=node_arry[prerequisites[i][0]].adjacent_node;
		node_arry[prerequisites[i][0]].adjacent_node=p;
	}
	finish=true;
	for(int i=0;finish&&i<numCourses;++i)
	{
		if(node_arry[i].traversed==0)
		  dfs(i);
	}
	free(node_arry);
	free(link_arry);
	return finish;
}

int main()
{
	int **prerequisites=(int**)malloc(sizeof(int*));
	prerequisites[0]=(int*)malloc(2*sizeof(int));
	prerequisites[0][0]=0;
	prerequisites[0][1]=1;
	bool finish=canFinish(2,prerequisites,1,2);
	return 0;
}