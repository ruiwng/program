#include  <stdio.h>

int main()
{
    printf("PERFECTION OUTPUT\n");
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        int t=n>>1;
        int sum=0;
        for(int i=1;i<=t;++i)
        {
            if(n%i==0)
                sum+=i;
        }
        printf("%5d  ",n);
        if(sum<n)
            printf("DEFICIENT\n");
        else if(sum>n)
            printf("ABUNDANT\n");
        else
            printf("PERFECT\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
