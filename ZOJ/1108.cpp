#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;

struct mouse
{
    int weight,speed;
    int prev;
    int len;
    int index;
    mouse(int w=0,int s=0):weight(w),speed(s),prev(-1),len(1),index(0){
        
    }
    bool operator<(const mouse& m) const
    {
        return this->weight<m.weight;
    }
};

void print_index(const vector<mouse>& m_array,int i)
{
    if(i==-1)
        return;
    print_index(m_array,m_array[i].prev);
    printf("%d\n",m_array[i].index);
}

int main()
{
    mouse m;
    vector<mouse> mouse_array;
    int i=0;
    while(scanf("%d%d",&m.weight,&m.speed)!=EOF)
    {
        m.index=++i;
        mouse_array.push_back(m);
    }     
    sort(mouse_array.begin(),mouse_array.end());

    int length=mouse_array.size();
    int max_len=0;
    int max_index;
    for(int i=0;i<length;++i)
    {
        for(int j=i-1;j>=0;--j)
        {
            if(mouse_array[j].weight<mouse_array[i].weight&&mouse_array[j].speed>mouse_array[i].speed&&mouse_array[j].len+1>mouse_array[i].len)
            {
                mouse_array[i].len=mouse_array[j].len+1;
                mouse_array[i].prev=j;
            }
                
        }
        if(mouse_array[i].len>max_len)
        {
            max_len=mouse_array[i].len;
            max_index=i;
        }
    }
    printf("%d\n",max_len);
    print_index(mouse_array,max_index);
    return 0;
}
