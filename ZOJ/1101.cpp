#include  <stdio.h>
#include  <vector>
#include  <algorithm>
#include  <functional>
using namespace std;

struct sum
{
    int index1;
    int index2;
    int number;
    sum(int i1=0,int i2=0,int n=0):index1(i1),index2(i2),number(n){
    }
    bool operator>(const sum& s) const
    {
        return this->number>s.number;
    }
};
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        vector<int> all_numbers(n);
        for(int i=0;i<n;++i)
            scanf("%d",&all_numbers[i]);
        
        sort(all_numbers.begin(),all_numbers.end(),greater<int>());

        vector<sum> two_sums;
        int m=n*(n-1)/2;
        two_sums.reserve(m);
        for(int i=0;i<n-1;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                two_sums.push_back(sum(i,j,all_numbers[i]+all_numbers[j]));
            }
        }
        sort(two_sums.begin(),two_sums.end(),greater<sum>());

        bool success=false;
        int result;
        for(int i=0;!success&&i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(j==i)
                    continue;
                int temp=all_numbers[i]-all_numbers[j];
                vector<sum>::iterator iter=lower_bound(two_sums.begin(),two_sums.end(),sum(0,0,temp),greater<sum>());
                if(iter!=two_sums.end()&&iter->number==temp&&iter->index1!=i&&iter->index2!=i)
                {
                    result=temp;
                    success=true;
                    break;
                }
                  
            }
        }
        if(success)
            printf("%d\n",result);
        else
            printf("no solution\n");
    }
    return 0;
}
