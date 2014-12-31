#include  <stdio.h>

int connections[21][21];
#define   MAX_DIST      0x00ffffff
int main()
{
    int set_number=0;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=20;++i)
           for(int j=1;j<=20;++j)
             connections[i][j]=MAX_DIST;
        for(int i=0;i<n;++i)
        {
            int temp;
            scanf("%d",&temp);
            connections[1][temp]=connections[temp][1]=1;
        }
        for(int i=2;i<=19;++i)
        {
            scanf("%d",&n);
            for(int j=0;j<n;++j)
            {
                int temp;
                scanf("%d",&temp);
                connections[i][temp]=connections[temp][i]=1;
            }
        }
        for(int i=1;i<=20;++i)
        {
            for(int j=1;j<=20;++j)
            {
                for(int k=1;k<=20;++k)
                {
                    if(connections[j][i]+connections[i][k]<connections[j][k])
                        connections[j][k]=connections[j][i]+connections[i][k];
                }
            }
        }

        int query_number;
        printf("Test Set #%d\n",++set_number);
        scanf("%d",&query_number);
        for(int i=0;i<query_number;++i)
        {
            int source,dest;
            scanf("%d%d",&source,&dest);
            printf("%d to %d: %d\n",source,dest,connections[source][dest]);
        }
        printf("\n");
    }
    return 0;
}
