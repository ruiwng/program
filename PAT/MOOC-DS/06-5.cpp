#include  <stdio.h>
#include  <vector>
#include  <set>
#include  <algorithm>
using namespace std;

int time_info[101][101];

struct node_info
{
    set<int> enter_node;
    set<int> leave_node;
    int complete_time;
    bool flag;
    vector<int> prev;
    node_info():enter_node(set<int>()),leave_node(set<int>()),complete_time(0),flag(false),prev(vector<int>()){
        
    }
};

struct path_info
{
    int start;
    int end;
    path_info(int s=0,int e=0):start(s),end(e){
        
    }
    bool operator<(const path_info& p) const
    {
        if(this->start!=p.start)
           return this->start<p.start;
        return this->end>p.end;
    }
};

vector<node_info> node_array;
set<path_info> path_array;
void print_path(int index)
{
    const vector<int>& prev_ref=node_array[index].prev;
    int len=prev_ref.size();
    for(int i=0;i<len;++i)
    {
        path_array.insert(path_info(prev_ref[i],index));
        print_path(prev_ref[i]);
    }
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        node_array.clear();
        node_array.assign(n+1,node_info());
        for(int i=0;i<m;++i)
        {
            int start,end,t;
            scanf("%d%d%d",&start,&end,&t);
            node_array[start].leave_node.insert(end);
            node_array[end].enter_node.insert(start);
            time_info[start][end]=t;
        }

        int min_time=0;
        int num=n;
        while(true)
        {
            int i=1;
            for(;i<=n;++i)
            {
                if(node_array[i].enter_node.empty()&&!node_array[i].flag)
                {
                    node_array[i].flag=true;
                    break;
                }
            }
            if(i==n+1)
                break;
            --num;
            if(min_time<node_array[i].complete_time)
                min_time=node_array[i].complete_time;
            const set<int>& leave_ref=node_array[i].leave_node;
            for(set<int>::const_iterator iter=leave_ref.begin();iter!=leave_ref.end();++iter)
            {
                if(node_array[i].complete_time+time_info[i][*iter]>node_array[*iter].complete_time)
                {
                    node_array[*iter].complete_time=node_array[i].complete_time+time_info[i][*iter];
                    node_array[*iter].prev.clear();
                    node_array[*iter].prev.push_back(i);
                }
                else if(node_array[i].complete_time+time_info[i][*iter]==node_array[*iter].complete_time)
                    node_array[*iter].prev.push_back(i);
                node_array[*iter].enter_node.erase(i);
            }
        }
        if(num!=0)
            printf("0\n");
        else
        {
            path_array.clear();
            printf("%d\n",min_time);
            for(int j=n;j>0;--j)
            {
                if(node_array[j].complete_time==min_time)
                    print_path(j);
            }
            for(set<path_info>::iterator iter=path_array.begin();iter!=path_array.end();++iter)
                printf("%d->%d\n",iter->start,iter->end);
        }
    }
    return 0;
}
