#include  <stdio.h>
#include  <vector>
#include  <set>
using namespace std;

struct node_info
{
    set<int> enter_node;
    set<int> leave_node;
    bool flag;
    int complete_time;
    node_info():enter_node(set<int>()),leave_node(set<int>()),flag(false),complete_time(0){
        
    }
};

int dist_info[100][100];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        vector<node_info> node_array(n);
        for(int i=0;i<m;++i)
        {
            int start,end,t;
            scanf("%d%d%d",&start,&end,&t);
            dist_info[start][end]=t;
            node_array[start].leave_node.insert(end);
            node_array[end].enter_node.insert(start);
        }
        int num=n;
        int min_complete=0;
        while(true)
        {
            int i=0;
            for(;i<n;++i)
            {
                if(node_array[i].enter_node.empty()&&!node_array[i].flag)
                {
                    node_array[i].flag=true;
                    break;
                }
            }
            if(min_complete<node_array[i].complete_time)
                min_complete=node_array[i].complete_time;
            if(i==n)
                break;
            --num;
            const set<int>& leave_ref=node_array[i].leave_node;
            for(set<int>::const_iterator iter=leave_ref.begin();iter!=leave_ref.end();++iter)
            {
                if(node_array[i].complete_time+dist_info[i][*iter]>node_array[*iter].complete_time)
                    node_array[*iter].complete_time=node_array[i].complete_time+dist_info[i][*iter];
                node_array[*iter].enter_node.erase(i);
            }
        }
        if(num!=0)
            printf("Impossible\n");
        else
            printf("%d\n",min_complete);
    }
    return 0;
}
