#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;

vector<vector<int> > result;
vector<int> number_array;
int num;

void traverse(vector<int> array,int index)
{
    if(index==num)
        return;
    traverse(array,index+1);
    array.push_back(number_array[index]);
    if(array.size()>1)
    {
        int len=array.size();
        int sum=0;
        for(int i=0;i<len;++i)
            sum+=array[i];
        vector<int>::iterator iter=lower_bound(number_array.begin(),number_array.end(),sum);
        if(iter==number_array.end())
            return;
        else if(*iter==sum)
            result.push_back(array);
    }
    traverse(array,index+1);
}

struct comp_func
{
    bool operator()(const vector<int>& lhs,const vector<int>& rhs) const
    {
        if(lhs.size()!=rhs.size())
            return lhs.size()<rhs.size();
        int len=lhs.size();
        for(int i=0;i<len;++i)
        {
            if(lhs[i]!=rhs[i])
                return lhs[i]<rhs[i];
        }
    }
};

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d",&num);
            number_array.clear();
            number_array.reserve(num);
            for(int j=0;j<num;++j)
            {
                int t;
                scanf("%d",&t);
                number_array.push_back(t);
            }

            sort(number_array.begin(),number_array.end());

            traverse(vector<int>(),0);
            sort(result.begin(),result.end(),comp_func());
            int len=result.size();
            if(len==0)
                printf("Can't find any equations.\n");
            else
            {
                 for(int j=0;j<len;++j)
                 {
                   const vector<int>& t=result[j];
                   int k=t.size();
                   int sum=0;
                   for(int m=0;m<k;++m)
                   {
                      printf("%d%c",t[m],m==k-1?'=':'+');
                      sum+=t[m];
                   }
                   printf("%d\n",sum);
                 }
            }
            printf("\n");
            result.clear();
        }
    }
    return 0;
}
