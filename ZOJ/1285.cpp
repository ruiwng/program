#include  <stdio.h>
#include  <string.h>
#include  <map>
#include  <string>
using namespace std;

int warehouses[31][31];

#define MAX_VALUE      0x00ffffff

int main()
{
    int n;
    printf("SHIPPING ROUTES OUTPUT\n\n");
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            map<string,int> index_info;
            int M,N,P;
            scanf("%d%d%d",&M,&N,&P);
            for(int j=0;j<M;++j)
               for(int k=0;k<M;++k)
                  warehouses[j][k]=MAX_VALUE;
            for(int j=0;j<M;++j)
            {
                char name[10];
                scanf("%s",name);
                index_info[name]=j;
            }
            for(int j=0;j<N;++j)
            {
                char start[5],end[5];
                scanf("%s %s",start,end);
                int index1=index_info[start];
                int index2=index_info[end];
                warehouses[index1][index2]=warehouses[index2][index1]=1;
            }
            for(int j=0;j<M;++j)
            {
                for(int m=0;m<M;++m)
                {
                    for(int k=0;k<M;++k)
                    {
                        if(warehouses[m][j]+warehouses[j][k]<warehouses[m][k])
                            warehouses[m][k]=warehouses[m][j]+warehouses[j][k];
                    }
                }
            }
            printf("DATA SET %d\n\n",i+1);
            for(int j=0;j<P;++j)
            {
                int size;
                char start[5],end[5];
                scanf("%d%s%s",&size,start,end);
                int index1=index_info[start];
                int index2=index_info[end];
                if(warehouses[index1][index2]==MAX_VALUE)
                    printf("NO SHIPMENT POSSIBLE\n");
                else
                    printf("$%d\n",warehouses[index1][index2]*size*100);
            }
            printf("\n");
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
