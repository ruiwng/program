#include  <stdio.h>
#include  <string.h>
#include  <queue>
#include  <bitset>
using namespace std;

struct node
{
    int index;
    int layer;
    node(int i=0,int l=0):index(i),layer(l){
        
    }
};
bitset<100020000> connections;
int main()
{
    int n,m;
    freopen("test.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        connections.reset();
        for(int i=0;i<m;++i)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            connections.set(x*10001+y);
            connections.set(y*10001+x);
        }
        char traversed[10001];
        for(int i=1;i<=n;++i)
        {
            memset(traversed,0,sizeof(traversed));
            queue<node> node_queue;
            node_queue.push(node(i));
            traversed[i]=1;
            int number=0;
            while(!node_queue.empty())
            {
                node t=node_queue.front();
                ++number;
                node_queue.pop();
                if(t.layer>=6)
                    continue;
                for(int j=1;j<=n;++j)
                {
                    if(connections.test(t.index*10001+j)&&traversed[j]==0)
                    {
                        traversed[j]=1;
                        node_queue.push(node(j,t.layer+1));
                    }
                }
            }
            printf("%d: %.2f%%\n",i,static_cast<double>(number)*100/n);
        }
    }
    return 0;
}
