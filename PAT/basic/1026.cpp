#include  <stdio.h>

int main()
{
    unsigned int start,end;
    while(scanf("%u %u",&start,&end)!=EOF)
    {
        unsigned int length=(end-start)/100;
        unsigned int ss=length%60;
        if((end-start)%100>=50)
            ++ss;
        unsigned int temp=length/60;
        unsigned int mm=temp%60;
        temp/=60;
        printf("%02u:%02u:%02u\n",temp,mm,ss);
    }
    return 0;
}
