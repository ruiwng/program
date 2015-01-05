#include  <stdio.h>
#include  <vector>
using namespace std;

#define   MAX_DIST    0x3fffffff

struct info
{
    int dist;
    int price;
};

info info_array[500][500];

struct record
{
    int current_dist;
    int current_price;
    bool flag;
    record(int d=MAX_DIST,int p=0,bool f=false):current_dist(d),current_price(p),flag(f){
        
    }
};

int main()
{
    int n,m,s,d;
    while(scanf("%d%d%d%d",&n,&m,&s,&d)!=EOF)
    {
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                info_array[i][j].dist=MAX_DIST;
        for(int i=0;i<n;++i)
            info_array[i][i].dist=0;
        for(int i=0;i<m;++i)
        {
            int start,end,d,p;
            scanf("%d%d%d%d",&start,&end,&d,&p);
            info_array[start][end].dist=d;
            info_array[start][end].price=p;
            info_array[end][start]=info_array[start][end];
        }

        vector<record> record_array(n);
        record_array[s].current_dist=0;
        while(true)
        {
            int max_dist=MAX_DIST;
            int current_index;
            for(int i=0;i<n;++i)
            {
                if(!record_array[i].flag&&record_array[i].current_dist<max_dist)
                {
                    current_index=i;
                    max_dist=record_array[i].current_dist;
                }
            }
            if(current_index==d)
                break;
            record_array[current_index].flag=true;
            for(int i=0;i<n;++i)
            {
                if(record_array[i].flag||info_array[current_index][i].dist==MAX_DIST)
                    continue;
                if(record_array[current_index].current_dist+info_array[current_index][i].dist<record_array[i].current_dist)
                {
                    record_array[i].current_dist=record_array[current_index].current_dist+info_array[current_index][i].dist;
                    record_array[i].current_price=record_array[current_index].current_price+info_array[current_index][i].price;
                }
                else if(record_array[current_index].current_dist+info_array[current_index][i].dist==record_array[i].current_dist)
                {
                    if(record_array[current_index].current_price+info_array[current_index][i].price<record_array[i].current_price)
                        record_array[i].current_price=record_array[current_index].current_price+info_array[current_index][i].price;
                }
            }
            
        }
        printf("%d %d\n",record_array[d].current_dist,record_array[d].current_price);
    }
    return 0;
}
