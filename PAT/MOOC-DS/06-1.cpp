#include  <stdio.h>
#include  <math.h>
#include  <vector>
#include  <queue>
#include  <algorithm>
using namespace std;

double distance_info[101][101];

struct pos
{
    int x;
    int y;
    int layer;
    int prev;
    pos(int x1=0,int y1=0,int l=-1,int p=-1):x(x1),y(y1),layer(l),prev(p){
        
    }
    bool operator<(const pos& p) const
    {
        if(this->x!=p.x)
            return abs(this->x)<abs(p.x);
        return abs(this->y)<abs(p.y);
    }
};

vector<pos> pos_array;

void print_path(int index)
{
    if(index==0)
        return;
    print_path(pos_array[index].prev);
    printf("%d %d\n",pos_array[index].x,pos_array[index].y);
}
int main()
{
    int n,d;
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        pos_array.clear();
        pos_array.reserve(n+1);
        pos_array.push_back(pos(0,0));
        for(int i=0;i<n;++i)
        {
            pos temp;
            scanf("%d%d",&temp.x,&temp.y);
            pos_array.push_back(temp);
        }
        sort(pos_array.begin(),pos_array.end());

        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n+1;++j)
            {
                int temp1=pos_array[i].x-pos_array[j].x;
                int temp2=pos_array[i].y-pos_array[j].y;
                distance_info[i][j]=sqrt(temp1*temp1+temp2*temp2);
                distance_info[j][i]=distance_info[i][j];
            }
        }       
        queue<int> pos_queue;
        pos_queue.push(0);
        pos_array[0].layer=0;
        while(!pos_queue.empty())
        {
            int t=pos_queue.front();
            if(50+pos_array[t].x<=d||50-pos_array[t].x<=d||
               50+pos_array[t].y<=d||50-pos_array[t].y<=d)
            {
                printf("%d\n",pos_array[t].layer+1);
                print_path(t);
                break;
            }
            pos_queue.pop();
            for(int i=1;i<n+1;++i)
            {
                if(i==t||pos_array[i].prev!=-1)
                    continue;
                double dist=distance_info[t][i];
                if(t==0)
                    dist-=7.5;
                if(dist<=d)
                {
                    pos_array[i].prev=t;
                    pos_array[i].layer=pos_array[t].layer+1;
                    pos_queue.push(i);
                }
            }
        }
        if(pos_queue.empty())
            printf("0\n");
    }
    return 0;
}
