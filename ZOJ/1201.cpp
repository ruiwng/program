#include  <stdio.h>
#include  <string.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        char str[3];
        scanf("%s",str);
        int position[51];
        if(str[0]=='P')
        {
            
            for(int i=1;i<=n;++i)
            {
                int temp;
                scanf("%d",&temp);
                position[temp]=i;
            }
            for(int i=1;i<=n;++i)
            {
                int number=0;
                for(int j=i+1;j<=n;++j)
                {
                    if(position[j]<position[i])
                        ++number;
                }
                printf("%d%c",number,i==n?'\n':' ');
            }
        }
        else
        {
            memset(position,0,sizeof(position));
            for(int i=1;i<=n;++i)
            {
                int temp;
                scanf("%d",&temp);
                int number=0;
                for(int j=1;j<=n;++j)
                {
                    if(position[j]==0)
                    {
                        if(++number==temp+1)
                        {
                            position[j]=i;
                            break;
                        }
                    }
                }
            }
            for(int i=1;i<=n;++i)
                printf("%d%c",position[i],i==n?'\n':' ');
        }
    }
    return 0;
}
