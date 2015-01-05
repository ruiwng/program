#include  <stdio.h>
#include  <vector>
#include  <queue>
#include  <deque>
#include  <functional>
using namespace std;

vector<int> disjoint_sets;

int disjoint_find(int index)
{
    if(disjoint_sets[index]==0)
        return index;
    return disjoint_sets[index]=disjoint_find(disjoint_sets[index]);
}

struct dist_info
{
    int start;
    int end;
    int price;
    dist_info(int s=0,int e=0,int p=0):start(s),end(e),price(p){
        
    }
    bool operator>(const dist_info& d) const
    {
        return this->price>d.price;
    }
};

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        disjoint_sets.clear();
        disjoint_sets.assign(n+1,0);
        priority_queue<dist_info,deque<dist_info>,greater<dist_info> > dist_queue;
        for(int i=0;i<m;++i)
        {
            int s,e,d;
            scanf("%d%d%d",&s,&e,&d);
            dist_queue.push(dist_info(s,e,d));
        }
        int min_price=0;
        while(!dist_queue.empty())
        {
            dist_info d=dist_queue.top();
            int parent1=disjoint_find(d.start);
            int parent2=disjoint_find(d.end);
            if(parent1!=parent2)
            {
                disjoint_sets[parent2]=parent1;
                min_price+=d.price;
                if(--n==1)
                    break;
            }
            dist_queue.pop();
        }
        if(dist_queue.empty())
            printf("-1\n");
        else
            printf("%d\n",min_price);
    }
    return 0;
}
