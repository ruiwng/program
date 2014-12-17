#include  <stdio.h>
#include  <math.h>

int main()
{
    int sum;
    char ch[2];
    while(scanf("%d %s",&sum,ch)!=EOF)
    {
        int n=sqrt((sum+1)/2);
        for(int i=n;i>=1;--i)
        {
            for(int j=1;j<=n-i;++j)
                printf(" ");
            for(int j=1;j<=2*i-1;++j)
                printf("%c",ch[0]);
            printf("\n");
        }
        for(int i=2;i<=n;++i)
        {
            for(int j=1;j<=n-i;++j)
                printf(" ");
            for(int j=1;j<=2*i-1;++j)
                printf("%c",ch[0]);
            printf("\n");
        }
        printf("%d\n",sum-2*n*n+1);
    }
    return 0;
}
