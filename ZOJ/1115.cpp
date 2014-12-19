#include  <stdio.h>

int main()
{
    char str[1000];
    while(scanf("%s",str)!=EOF)
    {
        int n=0;
        char* p=str;
        while(*p!='\0')
            n+=*p++-'0';
        if(n==0)
            break;
        while(n>=10)
        {
            int temp=n;
            n=0;
            while(temp!=0)
            {
                n+=temp%10;
                temp/=10;
            }
        }
        printf("%d\n",n);
    }
    return 0;
}
