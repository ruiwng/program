#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;

unsigned int N,p;
vector<unsigned long long> num_array;

int main()
{
    while(scanf("%u %u",&N,&p)!=EOF)
    {
        num_array.resize(N);
        for(unsigned int i=0;i<N;++i)
            scanf("%llu",&num_array[i]);
        sort(num_array.begin(),num_array.end());
        unsigned int max_count=0;
        for(unsigned int i=0;i<N;++i)
        {
            unsigned int low_bound=i+1;
            unsigned int high_bound=N-1;
            unsigned int temp=num_array[i]*p;
            if(temp>=num_array[high_bound])
            {
                if(high_bound-i+1>max_count)
                    max_count=high_bound-i+1;
                break;
            }
            else if(temp<num_array[low_bound])
            {
                if(1>max_count)
                    max_count=1;
                continue;
            }
            else
            {
                unsigned int median;
                while(low_bound<=high_bound)
                {
                    median=(low_bound+high_bound)>>1;
                    if(temp>num_array[median])
                        low_bound=median+1;
                    else if(temp<num_array[median])
                        high_bound=median-1;
                    else
                        break;
                }
                while(num_array[median]<=temp)
                    ++median;
                if(median-i>max_count)
                    max_count=median-i;
            }
        }
        printf("%u\n",max_count);
        
    }
    return 0;
}
