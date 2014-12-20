#include  <stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            if(i!=0)
                printf("\n");
            int base;
            while(scanf("%d",&base)!=EOF&&base)
            {
                char str[100];
                scanf("%s",str);
                char* p=str;
                int digit_sum=0;
                while(*p!='\0')
                    digit_sum+=*p++-'0';
                int num=0;
                p=str;
                while(*p!='\0')
                    num=num*base+*p++-'0';
                if(num%digit_sum==0)
                    printf("yes\n");
                else
                    printf("no\n");
            }
        }
    }
    return 0;
}
