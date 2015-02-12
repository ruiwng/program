#include  <stdio.h>
#include  <vector>
using namespace std;

int main()
{
    int test_cases;
    while(scanf("%d",&test_cases)!=EOF)
    {
        for(int i=0;i<test_cases;++i)
        {
            vector<int> poly[3];
            for(int j=0;j<3;++j)
            {
                int m;
                scanf("%d",&m);
                if(m==0)
                    return -1;
                poly[j].reserve(m);
                for(int k=0;k<m;++k)
                {
                    int temp;
                    scanf("%d",&temp);
                    poly[j].push_back(temp);
                }
            }
            int m=poly[0].size()+poly[1].size()-1;
            vector<int> product(m,0);
            for(unsigned int j=0;j<poly[0].size();++j)
            {
                for(unsigned int k=0;k<poly[1].size();++k)
                {
                    if(poly[0][j]==1&&poly[1][k]==1)
                        product[j+k]^=1;
                }
            }
            int n=poly[2].size();
            for(int j=0;j<=m-n;++j)
            {
                if(product[j]==0)
                    continue;
                else
                    product[j]=0;
                for(int k=1;k<n;++k)
                    product[j+k]^=poly[2][k];
            }
            bool flag=false;
            for(int j=0;j<m;++j)
            {
                if(!flag&&product[j]==1)
                {
                    flag=true;
                    printf("%d",product.size()-j);
                }
                if(flag)
                    printf(" %d",product[j]);
            }
            if(!flag)
                printf("0");
            printf("\n");
        }
    }
    return 0;
}

    
        
