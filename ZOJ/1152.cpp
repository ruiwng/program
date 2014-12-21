#include  <stdio.h>

int main()
{
    int num;
    while(scanf("%d",&num)!=EOF)
    {
        for(int i=0;i<num;++i)
        {
            if(i!=0)
                printf("\n");
            int n,m;
            int case_num=0;
            while(scanf("%d%d",&n,&m)!=EOF)
            {
                if(n==0&&m==0)
                    break;
                int pairs_num=0;
                for(int j=1;j<n-1;++j)
                {
                    for(int k=j+1;k<n;++k)
                    {
                        if((j*j+k*k+m)%(j*k)==0)
                            ++pairs_num;
                    }
                }
                printf("Case %d: %d\n",++case_num,pairs_num);
            }
        }
    }
    return 0;
}
