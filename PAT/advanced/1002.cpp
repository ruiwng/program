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
	list<NODE>::iterator iter1=nodeList[0].begin(),iter2=nodeList[1].begin();
    while(iter1!=nodeList[0].end()&&iter2!=nodeList[1].end())
    {
		 if(iter1->N>iter2->N)
		 {
		    Lst.push_back(*iter1);
	        iter1++;
		 }
		 else if(iter1->N==iter2->N)
		 {
			 iter1->K+=iter2->K;
			 if(iter1->K!=0)
			    Lst.push_back(*iter1);
			 iter1++;
			 iter2++;
		 }
		 else 
		 {
			 Lst.push_back(*iter2);
			 iter2++;
		 }
	}
	while(iter1!=nodeList[0].end())
	{
		 Lst.push_back(*iter1);
		 iter1++;
    }
    while(iter2!=nodeList[1].end())
	{
		 Lst.push_back(*iter2);
		 iter2++;
	}
	printf("%d",Lst.size());
		   
	for(list<NODE>::const_iterator it=Lst.begin();it!=Lst.end();++it)
	   printf(" %d %.1f",it->N,it->K);
	printf("\n");
	return 0;
}