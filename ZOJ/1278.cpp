#include  <stdio.h>
#include  <map>
using namespace std;
int main()
{
    int Z,I,M,L;
    int case_number=0;
    while(scanf("%d%d%d%d",&Z,&I,&M,&L)!=EOF)
    {
        map<int,int> index_info;
        if(Z==0&&I==0&&M==0&&L==0)
            break;
        int index=0;
        index_info.insert(make_pair(L,index++));
        while(true)
        {
            L=(Z*L+I)%M;
            map<int,int>::iterator iter=index_info.find(L);
            if(iter!=index_info.end())
            {
                if(iter->second!=0)
                    ++index;
                printf("Case %d: %d\n",++case_number,index-iter->second);
                break;
            }
            index_info.insert(make_pair(L,++index));
        }
    }
    return 0;
}
