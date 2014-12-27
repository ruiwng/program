#include  <stdio.h>
#include  <string.h>
#include  <vector>
#include  <queue>
#include  <algorithm>
using namespace std;

int traversed[15];

vector<vector<int> > connection;

void dfs(vector<int>& result,int index)
{
    if(traversed[index]==1)
        return;
    traversed[index]=1;
    result.push_back(index);
    const vector<int>& neighbor=connection[index];
    int len=neighbor.size();
    for(int i=0;i<len;++i)
        dfs(result,neighbor[i]);
}

void print_result(const vector<int>& result)
{
    printf("{ ");
    int len=result.size();
    for(int i=0;i<len;++i)
        printf("%d ",result[i]);
    printf("}\n");
}

int main()
{
    int n,e;
    while(scanf("%d%d",&n,&e)!=EOF)
    {
        connection.assign(n,vector<int>());
        for(int i=0;i<e;++i)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            connection[x].push_back(y);
            connection[y].push_back(x);
        }

        for(int i=0;i<n;++i)
            sort(connection[i].begin(),connection[i].end());
        
        memset(traversed,0,sizeof(traversed));
        for(int i=0;i<n;++i)
        {
            if(traversed[i]==1)
                continue;
            vector<int> result;
            dfs(result,i);
            print_result(result);
        }

        memset(traversed,0,sizeof(traversed));
        for(int i=0;i<n;++i)
        {
            if(traversed[i]==1)
                continue;
            traversed[i]=1;
            vector<int> result;
            queue<int> node_queue;
            node_queue.push(i);
            while(!node_queue.empty())
            {
                int temp=node_queue.front();
                result.push_back(temp);
                node_queue.pop();
                const vector<int>& neighbor=connection[temp];
                int length=neighbor.size();
                for(int j=0;j<length;++j)
                {
                    if(traversed[neighbor[j]]==0)
                    {
                        traversed[neighbor[j]]=1;
                        node_queue.push(neighbor[j]);
                    }
                }
            }
            print_result(result);
        }
    }
    return 0;
}
