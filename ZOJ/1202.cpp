#include  <stdio.h>
#include  <map>
#include  <math.h>
using namespace std;

int func(int m,int n)
{
    if(m==n)
        return 1;
    int k=1;
    for(int i=0;i<n;++i)
        k*=m-i;
    for(int i=1;i<=n;++i)
        k/=i;
    return k;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        map<int,int> capacity_record;
        int sum=0;
        for(int i=0;i<n;++i)
        {
            int t;
            scanf("%d",&t);
            sum+=t;
            ++capacity_record[t];
        }
        int kind_num=1;
        for(map<int,int>::iterator iter=capacity_record.begin();iter!=capacity_record.end();++iter)
        {
            kind_num*=func(sum,iter->first*iter->second);
            sum-=iter->first*iter->second;
            if(iter->second!=1)
            {
                int k=iter->second;
                int t=iter->first*iter->second;
                for(int j=0;j<k;++j)
                {
                    kind_num*=func(t,iter->first);
                    t-=iter->first;
                }
                int temp=1;
                while(k)
                    temp*=k--;
                kind_num/=temp;
            }
        }
        printf("%d\n",kind_num);
    }
    return 0;
}
