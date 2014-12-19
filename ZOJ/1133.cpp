#include  <stdio.h>
#include  <math.h>

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
            int prime_sum=0;
            for(int i=2;i<=temp;++i)
            {
                while(k%i==0)
                {
                    k/=i;
                    temp=sqrt(static_cast<double>(k));
                    prime_sum+=sum_digit(i);
                }
            }

            if(j==k)
                continue;
            if(k!=1)
                prime_sum+=sum_digit(k);
            if(prime_sum==sum_digit(j))
            {
                printf("%d\n",j);
                break;
            }
        }
    }
    return 0;
}
