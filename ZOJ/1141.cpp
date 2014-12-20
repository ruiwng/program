#include  <stdio.h>
#include  <string.h>
#include  <vector>
using namespace std;

int main()
{
    int num_node;
    while(scanf("%d",&num_node)!=EOF)
    {
        vector<int> ancestors(num_node+1,0);
        vector<int> ancestor_time(num_node+1,0);
        for(int i=0;i<num_node;++i)
        {
            int current_node,node_number;
            scanf("%d:(%d)",&current_node,&node_number);
            for(int j=0;j<node_number;++j)
            {
                int node;
                scanf("%d",&node);
                ancestors[node]=current_node;
            }
            
        }
        int data_sets;
        scanf("%d",&data_sets);
        getchar();
        char str[1000];
        vector<int> ancestors_tag;
        while(fgets(str,1000,stdin)!=NULL)
        {
            char* p=str;
            int node1,node2;
            
            while(sscanf(p,"(%d,%d)",&node1,&node2)==2)
            {
                ancestors_tag.assign(num_node+1,0);
                 int t=node1;
                 while(true)
                 {
                     ancestors_tag[t]=1;
                    t=ancestors[t];
                    if(t==0)
                       break;
                 }
                 while(true)
                 {
                     if(ancestors_tag[node2]==1)
                        break;
                     node2=ancestors[node2];
                 }
                 ++ancestor_time[node2];
                 --data_sets;
                 ++p;
                 p=strchr(p,'(');
                 if(p==NULL)
                     break;
            }
            if(data_sets==0)
                break;
        }
        for(int i=0;i<data_sets;++i)
        {
            int node1,node2;
            scanf("(%d,%d)",&node1,&node2);
           
        }
        for(int i=1;i<=num_node;++i)
        {
            if(ancestor_time[i]!=0)
                printf("%d:%d\n",i,ancestor_time[i]);
        }
    }
    return 0;
}
