#include  <stdio.h>
#include  <string.h>
#include  <vector>
#include  <queue>
#include  <math.h>
using namespace std;

double distance_array[101][101];

struct pos
{
    double x;
    double y;
    pos(double x1=0.0,double y1=0.0):x(x1),y(y1){
        
    }
};

int main()
{
    int n;
    double d;
    while(scanf("%d%lf",&n,&d)!=EOF)
    {
        vector<pos> pos_array;
        pos_array.reserve(n+1);
        pos_array.push_back(pos());
        for(int i=0;i<n;++i)
        {
            pos temp;
            scanf("%lf%lf",&temp.x,&temp.y);
            pos_array.push_back(temp);
        }
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n+1;++j)
            {
                int len_x=pos_array[i].x-pos_array[j].x;
                int len_y=pos_array[i].y-pos_array[j].y;
                distance_array[i][j]=sqrt(len_x*len_x+len_y*len_y);
                distance_array[j][i]=distance_array[i][j];
            }
        }
        bool success=false;
        int traversed[101];
        memset(traversed,0,sizeof(traversed));
        queue<int> pos_queue;
        pos_queue.push(0);
        while(!pos_queue.empty())
        {
            int t=pos_queue.front();
            if((50-pos_array[t].x)<=d||
               (pos_array[t].x+50)<=d||
               (50-pos_array[t].y)<=d||
               (pos_array[t].y+50)<=d)
            {
                success=true;
                break;
            }
            pos_queue.pop();
            for(int i=1;i<=n;++i)
            {
                if(i==t||traversed[i])
                    continue;
                int temp=distance_array[t][i];
                if(t==0)
                    temp-=15.0;
                if(temp<=d)
                {
                    pos_queue.push(i);
                    traversed[i]=1;
                }
            }
        }
        if(success)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

