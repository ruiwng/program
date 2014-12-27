#include  <stdio.h>
#include  <string.h>

int main()
{
    int n;
    while(scanf("%d\n",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            char str[80];
            fgets(str,80,stdin);
            char *p=str;
            while(*p!='\n')
                ++p;
            --p;
            while(p>=str)
                printf("%c",*p--);
            printf("\n");
        }
    }
    return 0;
}
