#include  <stdio.h>
#include  <map>
using namespace std;

int main()
{
    int m,n;
    int case_number=0;
    map<int,int> node_info;
    bool is_tree=true;
    int non_root=0;
    freopen("test.txt","r",stdin);
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m<0&&n<0)
            break;
        if(m==0&&n==0)
        {
            if(!node_info.empty()&&non_root+1!=node_info.size())
                is_tree=false;
            printf("Case %d is %sa tree.\n",++case_number,is_tree?"":"not ");
            node_info.clear();
            non_root=0;
            is_tree=true;
            continue;
        }
        if(is_tree)
        {
            if(m==n)
            {
                is_tree=false;
                continue;
            }
            if(node_info[m]==n)
            {
                is_tree=false;
                continue;
            }
             if(node_info[n]!=0&&node_info[n]!=m)
             {
                 is_tree=false;
                 continue;
             }
             node_info[n]=m;
             ++non_root;
        }
       
    }
    return 0;
}
