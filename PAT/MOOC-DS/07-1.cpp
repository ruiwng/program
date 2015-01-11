#include  <stdio.h>
#include  <algorithm>
#include   <vector>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        vector<long int> number_array;
        number_array.reserve(n);
        for(int i=0;i<n;++i)
        {
            long int temp;
            scanf("%ld",&temp);
            number_array.push_back(temp);
        }
        sort(number_array.begin(),number_array.end());
        int len=number_array.size();
        for(int i=0;i<len;++i)
            printf("%ld%c",number_array[i],i==len-1?'\n':' ');
    }
    return 0;
}
