#include  <stdio.h>
#include  <vector>
using namespace std;
int main()
{
    int n,m,c;
    int sequence_number=0;
    while(scanf("%d%d%d",&n,&m,&c)!=EOF)
    {
        if(n==0&&m==0&&c==0)
            break;
        vector<int> device_array;
        device_array.reserve(n);
        for(int i=0;i<n;++i)
        {
            int t;
            scanf("%d",&t);
            device_array.push_back(t);
        }
        vector<int> state_array(n,0);
        int current_capacity=0;
        int max_capacity=0;
        bool flag=false;
        for(int i=0;i<m;++i)
        {
            int state;
            scanf("%d",&state);
            if(flag)
                continue;
            if(state_array[state-1]==0)
            {
                current_capacity+=device_array[state-1];
                state_array[state-1]=1;
            }
            else
            {
                current_capacity-=device_array[state-1];
                state_array[state-1]=0;
            }
            if(current_capacity>max_capacity)
                max_capacity=current_capacity;
            if(current_capacity>c)
                flag=true;
        }
        printf("Sequence %d\n",++sequence_number);
        if(flag)
            printf("Fuse was blown.\n");
        else
        {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n",max_capacity);
        }
        printf("\n");
    }
    return 0;
}
