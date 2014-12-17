#include  <stdio.h>
#include  <stdlib.h>
#include  <list>
using namespace std;

typedef struct
{
	int N;
	float K;
}NODE;

int main()
{
	list<NODE> nodeList[2];
	for(int i=0;i<2;i++)
    {
		 while(!nodeList[i].empty())
			 nodeList[i].pop_back();
	}
	for(int i=0;i<2;i++)
    {
	  int x;
	  scanf("%d",&x);
	  for(int j=0;j<x;j++)
	  {
		 NODE* p=(NODE*)malloc(sizeof(NODE));
		 scanf("%d %f",&(p->N),&(p->K));
	     nodeList[i].push_back(*p);
	  }
	}
	list<NODE> Lst;
	for(list<NODE>::const_iterator iter1=nodeList[0].begin();iter1!=nodeList[0].end();++iter1)
	{
		for(list<NODE>::const_iterator iter2=nodeList[1].begin();iter2!=nodeList[1].end();++iter2)
		{
			NODE* p=(NODE*)malloc(sizeof(NODE));
			p->K=iter1->K*iter2->K;
			p->N=iter1->N+iter2->N;
			
			list<NODE>::iterator iter=Lst.begin();
			while(iter!=Lst.end()&&iter->N>p->N)
				iter++;
			if(iter==Lst.end()||iter->N<p->N)
			    Lst.insert(iter,*p);
			else
			{
				iter->K+=p->K;
				if(iter->K==0)
					Lst.erase(iter);
				free(p);
			}
		}
	}
	
	printf("%d",Lst.size());
		   
	for(list<NODE>::const_iterator it=Lst.begin();it!=Lst.end();++it)
	   printf(" %d %.1f",it->N,it->K);
	printf("\n");
	return 0;
}