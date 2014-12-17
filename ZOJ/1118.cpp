#include  <stdio.h>
#include  <string.h>
#include  <map>
#include  <set>
#include  <vector>
#include  <queue>
using namespace std;
int n;

int main()
{
    int maze_number=0;
    while(scanf("%d",&n)!=EOF&&n)
    {
        getchar();
        int start=0;
        for(int i=0;i<n;++i)
        {
            int temp;
            scanf("%d",&temp);
            start=start*10+temp;
        }
        int end=0;
        for(int i=0;i<n;++i)
        {
            int temp;
            scanf("%d",&temp);
            end=end*10+temp;
        }
        bool e=false;
        map<int,vector<int> > adjacent_map;
        set<int> traversed_pos;
        while(true)
        {
            int pos1=0;
            for(int i=0;i<n;++i)
            {
                int temp;
                scanf("%d",&temp);
                if(temp==-1)
                {
                    e=true;
                    break;
                }
                pos1=pos1*10+temp;
            }
            if(e)
                break;
            int pos2=0;
            for(int i=0;i<n;++i)
            {
                int temp;
                scanf("%d",&temp);
                pos2=pos2*10+temp;
            }
            adjacent_map[pos1].push_back(pos2);
            adjacent_map[pos2].push_back(pos1);
        }
        bool success=false;
        queue<int> pos_queue;
        pos_queue.push(start);
        while(!success&&!pos_queue.empty())
        {
            int temp=pos_queue.front();
            if(temp==end)
            {
                success=true;
                break;
            }
            pos_queue.pop();
            vector<int>& adja_refer=adjacent_map[temp];
            for(vector<int>::iterator iter=adja_refer.begin();iter!=adja_refer.end();++iter)
            {
                if(traversed_pos.find(*iter)==traversed_pos.end())
                {
                    traversed_pos.insert(*iter);
                    pos_queue.push(*iter);
                }
            }
        }
        if(success)
            printf("Maze #%d can be travelled\n",++maze_number);
        else
            printf("Maze #%d cannot be travelled\n",++maze_number);
     }
    return 0;
}
