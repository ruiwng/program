#include  <stdio.h>
#include  <string.h>

int disjoints[10000];

int disjoints_find(int index)
{
    if(disjoints[index]==0)
        return index;
    else
        return disjoints[index]=disjoints_find(disjoints[index]);
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(disjoints,0,sizeof(disjoints));
        char oper[3];
        
        while(scanf("%s",oper)!=EOF)
        {
            if(oper[0]=='S')
                break;
            else if(oper[0]=='I')
            {
                int node1,node2;
                scanf("%d%d",&node1,&node2);
                int parent1=disjoints_find(node1);
                int parent2=disjoints_find(node2);
                if(parent1!=parent2)
                {
                    --n;
                    disjoints[parent2]=parent1;
                }
            }
            else if(oper[0]=='C')
            {
                int node1,node2;
                scanf("%d%d",&node1,&node2);
                int parent1=disjoints_find(node1);
                int parent2=disjoints_find(node2);
                if(parent1!=parent2)
                    printf("no\n");
                else
                    printf("yes\n");
            }
        }
        if(n==1)
            printf("The network is connected.\n");
        else
            printf("There are %d components.\n",n);
    }
    return 0;
}
