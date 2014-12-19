#include  <stdio.h>
#include  <math.h>
#include  <vector>
using namespace std;

int sum_digit(int n)
{
    int result=0;
    while(n!=0)
    {
        result+=n%10;
        n/=10;
    }
    return result;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int j=n+1;;++j)
        {
            int k=j;
            int temp=sqrt(static_cast<double>(k));
            vector<int> factors_array;
            for(int i=2;i<=temp;++i)
            {
                while(k%i==0)
                {
                    k/=i;
                    temp=sqrt(static_cast<double>(k));
                    factors_array.push_back(i);
                }
            }

            if(j==k)
                continue;
            if(k!=1)
                factors_array.push_back(k);
            int length=factors_array.size();
            int prime_sum=0;
            for(int i=0;i<length;++i)
                prime_sum+=sum_digit(factors_array[i]);
            if(prime_sum==sum_digit(j))
            {
                printf("%d\n",j);
                break;
            }
        }
    }
    return 0;
}
