#include  <stdio.h>

char photos[100000];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            if(i!=0)
                printf("\n");
            int num;
            char str[10000];
            scanf("%d",&num);
            int index=0;
            while(fgets(str,10000,stdin)!=NULL)
            {
                char* p=str;
                while(*p!='\n')
                {
                    if(*p=='U'||*p=='D')
                        photos[index++]=*p;
                    ++p;
                }
                if(index==num)
                    break;
            }
            int flip_oper=0;
            int current_pos=0;
            for(int i=1;i<num;++i)
            {
                if(photos[i]!=photos[current_pos])
                {
                    ++flip_oper;
                    current_pos=i;
                }
            }
            printf("%d\n",flip_oper);
        }
    }
    return 0;
}
