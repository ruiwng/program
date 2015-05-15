#include  <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct list_node
{
	int index;
	struct list_node *next;
};

struct node_info
{
	int preceding;
	struct list_node *adjacent;
};

int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize, int* returnSize) {
    struct node_info* node_arry=(struct node_info*)malloc(numCourses*sizeof(struct node_info));
	struct list_node* list_nodes=(struct list_node*)malloc(prerequisitesRowSize*sizeof(struct list_node));
	for(int i=0;i<numCourses;++i)
	{
		node_arry[i].preceding=0;
		node_arry[i].adjacent=NULL;
	}
	int index=0;
	for(int i=0;i<prerequisitesRowSize;++i)
	{
		struct list_node *p=&list_nodes[index++];
		++node_arry[prerequisites[i][0]].preceding;
		p->index=prerequisites[i][0];
		p->next=node_arry[prerequisites[i][1]].adjacent;
		node_arry[prerequisites[i][1]].adjacent=p;
	}
	int *result=(int*)malloc(numCourses*sizeof(int));
	*returnSize=0;
	while(true)
	{
		int j=0;
		while(j<numCourses)
		{
			if(node_arry[j].preceding==0)
			{
				node_arry[j].preceding=-1;
				break;
			}
			++j;
		}
		if(j==numCourses)
			break;
		result[(*returnSize)++]=j;
		struct list_node *p=node_arry[j].adjacent;
		while(p!=NULL)
		{
			--node_arry[p->index].preceding;
			p=p->next;
		}
	}
	free(node_arry);
	free(list_nodes);
	if(*returnSize!=numCourses)
		*returnSize=0;
	return result;
}

int main()
{
	int** prerequsites=(int**)malloc(4*sizeof(int*));
	for(int i=0;i<4;++i)
	   prerequsites[i]=(int*)malloc(2*sizeof(int));
	prerequsites[0][0]=1;
	prerequsites[0][1]=0;
	prerequsites[1][0]=2;
	prerequsites[1][1]=0;
	prerequsites[2][0]=3;
	prerequsites[2][1]=1;
	prerequsites[3][0]=3;
	prerequsites[3][1]=2;
	int returnSize;
	int* result=findOrder(4,prerequsites,4,2,&returnSize);
	return 0;
}