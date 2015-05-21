#include  <stdio.h>

int main()
{
    int start,end;
    while(scanf("%d %d",&start,&end)!=EOF)
    {
        int length=(end-start)/100;
        int ss=length%60;
        if((end-start)%100>=50)
            ++ss;
        int temp=length/60;
        int mm=temp%60;
        temp/=60;
        printf("%02d:%02d:%02d\n",temp,mm,ss);
    }
    return 0;
}
