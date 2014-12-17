
#include  <stdio.h>

int main()
{
    int n;
    int case_number=0;
    while(scanf("%d",&n)!=EOF&&n)
    {
        int order[10];
        for(int i=0;i<n;++i)
        {
            char temp[3];
            scanf("%s",temp);
            order[i]=temp[1]-'0';
        }
           
        char str[130];
        scanf("%s",str);

        int VVA;
        printf("S-Tree #%d:\n",++case_number);
        scanf("%d",&VVA);
        for(int i=0;i<VVA;++i)
        {
            char temp[10];
            scanf("%s",temp);
            int pos=1;
            for(int i=0;i<n;++i)
            {
                if(temp[order[i]-1]=='0')
                    pos<<=1;
                else
                    pos=(pos<<1)+1;
            }
            pos-=1<<n;
            printf("%c",str[pos]);
        }
        printf("\n\n");
    }
    return 0;
}
