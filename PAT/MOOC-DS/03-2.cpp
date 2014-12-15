#include  <stdio.h>
#include  <string.h>
#include  <queue>
#include  <vector>
using namespace std;

struct node
{
    int left_child;
    int right_child;
    node(int l=-1,int r=-1):left_child(l),right_child(r){}
};

int root_node[10];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        vector<node> node_array(n);
        memset(root_node,0,sizeof(root_node));
        getchar();
        for(int i=0;i<n;++i)
        {
            char str[20];
            fgets(str,20,stdin);
            char* p=str;
            int a,b;
            int temp=sscanf(p,"%d",&a);
            if(temp==1)
            {
                root_node[a]=1;
                node_array[i].left_child=a;
            }
            p=strchr(p,' ');
            temp=sscanf(p,"%d",&b);
            if(temp==1)
            {
                root_node[b]=1;
                node_array[i].right_child=b;
            }
        }
        int root;
        for(int i=0;i<n;++i)
        {
            if(root_node[i]==0)
            {
                root=i;
                break;
            }
        }
        queue<int> node_queue;
        node_queue.push(root);
        bool first=true;
        while(!node_queue.empty())
        {
            int node_temp=node_queue.front();
            node_queue.pop();
            if(node_array[node_temp].left_child==-1&&node_array[node_temp].right_child==-1)
            {
                if(first)
                    first=false;
                else
                    printf(" ");
                printf("%d",node_temp);
            }
            else
            {
                if(node_array[node_temp].left_child!=-1)
                     node_queue.push(node_array[node_temp].left_child);
                if(node_array[node_temp].right_child!=-1)
                     node_queue.push(node_array[node_temp].right_child);
            }
        }
        printf("\n");
    }
    return 0;
}
