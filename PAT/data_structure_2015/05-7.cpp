#include  <stdio.h>
#include  <string.h>

int disjoint_sets[10010];

int disjoint_find(int index)
{
	if(disjoint_sets[index]==0)
		return index;
	return disjoint_sets[index]=disjoint_find(disjoint_sets[index]);
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(disjoint_sets,0,(n+1)*sizeof(int));
		char operation[5];
		while(scanf("%s",operation)!=EOF)
		{
			if(operation[0]=='I')
			{
				int x,y;
				scanf("%d%d",&x,&y);
				int parent1=disjoint_find(x);
				int parent2=disjoint_find(y);
				if(parent1!=parent2)
				{
					--n;
					disjoint_sets[parent2]=parent1;
				}
			}
			else if(operation[0]=='C')
			{
				int x,y;
				scanf("%d%d",&x,&y);
				int parent1=disjoint_find(x);
				int parent2=disjoint_find(y);
				printf("%s\n",parent1==parent2?"yes":"no");
			}
			else
			{
				if(n==1)
					printf("The network is connected.\n");
				else
					printf("There are %d components.\n",n);
				break;
			}
		}
	}
	return 0;
}