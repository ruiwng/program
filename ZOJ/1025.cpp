#include  <stdio.h>
#include  <list>
using namespace std;

struct stick
{
    int length;
    int weight;
    stick(int l=0,int w=0):length(l),weight(w){
        
    }
    bool operator<(const stick& s) const
    {
        return this->length<s.length;
    }
};
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int j=0;j<n;++j)
        {
            list<stick> stick_array;
            int m;
            scanf("%d",&m);
            for(int i=0;i<m;++i)
            {
               stick stick_temp;
               scanf("%d%d",&stick_temp.length,&stick_temp.weight);
               stick_array.push_back(stick_temp);
            }
            stick_array.sort();

            bool first=true;
            stick temp;
            int setup_time=0;
            while(!stick_array.empty())
           {
               for(list<stick>::iterator iter=stick_array.begin();iter!=stick_array.end();)
               {
                  if(first||iter->weight>=temp.weight)
                  {
                    first=false;
                    list<stick>::iterator iter_temp(iter);
                    ++iter;
                    temp=*iter_temp;
                    stick_array.erase(iter_temp);
                  }
                  else
                    ++iter;
               }
               ++setup_time;
               first=true;
            }
           printf("%d\n",setup_time);
         }    
    }
    return 0;
}
