#include  <stdio.h>
#include  <string.h>
#include  <math.h>
#include  <queue>
#include  <deque>
#include  <vector>
#include  <functional>
using namespace std;

struct pos
{
    double x;
    double y;
    pos(double x1=0.0,double y1=0.0):x(x1),y(y1){
        
    }
};

struct dis_info
{
    int index1;
    int index2;
    double dist;
    dis_info(int i1=0,int i2=0,double d=0.0):index1(i1),index2(i2),dist(d){
        
    }
    bool operator>(const dis_info& d) const
    {
        return this->dist>d.dist;
    }
};

int disjoint_array[101];

int disjoint_find(int m)
{
    if(disjoint_array[m]==0)
        return m;
    else
        return disjoint_array[m]=disjoint_find(disjoint_array[m]);
}

int main()
{
    int n;
    int case_number=0;
    while(scanf("%d",&n)!=EOF&&n)
    {
        if(case_number!=0)
            printf("\n");
        vector<pos> pos_array;
        pos_array.reserve(n);
        for(int i=0;i<n;++i)
        {
            pos pos_temp;
            scanf("%lf%lf",&pos_temp.x,&pos_temp.y);
            pos_array.push_back(pos_temp);
        }
        priority_queue<dis_info,deque<dis_info>,greater<dis_info> > dis_queue;
        for(int i=0;i<n-1;++i)
        {
            for(int j=i+1;j<n;++j)
                dis_queue.push(dis_info(i+1,j+1,sqrt((pos_array[i].x-pos_array[j].x)*(pos_array[i].x-pos_array[j].x)+(pos_array[i].y-pos_array[j].y)*(pos_array[i].y-pos_array[j].y))));
        }

        memset(disjoint_array,0,sizeof(disjoint_array));
        double all_distance=0.0;
        while(n>1)
        {
            const dis_info& info_temp=dis_queue.top();
            int parent1=disjoint_find(info_temp.index1);
            int parent2=disjoint_find(info_temp.index2);
            if(parent1!=parent2)
            {
                all_distance+=info_temp.dist;
                disjoint_array[parent2]=parent1;
                --n;
            }
            dis_queue.pop();
        }
        printf("Case #%d:\n",++case_number);
        printf("The minimal distance is: %.2lf\n",all_distance);
    }
    return 0;
}
