#include  <stdio.h>
#include  <vector>
using namespace std;

int main()
{
    int S,W,C,K,M;
    while(scanf("%d%d%d%d%d",&S,&W,&C,&K,&M)!=EOF)
    {
        vector<int> time_array;
        time_array.push_back(M+S+W);
        int current_uint=C;
        int current_time;
        vector<int> start_array(K,0);
        start_array[0]=M+S;
        for(int i=1;i<K;++i)
            start_array[i]=start_array[0]+M*i;
        
        if(current_uint>=10000)
            current_time=time_array[0]+S;

        int pos=1;
        while(current_uint<10000)
        {
            for(int i=0;i<time_array.size();++i)
            {
                 if(pos<K&&start_array[pos]<=time_array[i]+2*S)
                    time_array.insert(time_array.begin()+i,start_array[pos++]+W);
                else
                    time_array[i]+=2*S+W;
                 int t=time_array.size();
                 if(t!=1&&time_array[(i-1+t)%t]+W>time_array[i])
                    time_array[i]=time_array[(i-1+t)%t]+W;
               
                current_uint+=C;
                if(current_uint>=10000)
                {
                    current_time=time_array[i]+S;
                    break;
                }
            }
        }
        printf("%d\n",current_time);
    }
    return 0;
}
