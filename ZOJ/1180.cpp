#include  <stdio.h>
#include  <string.h>

char number_array[1000010];

int digit_sum(int n)
{
    int result=0;
    while(n!=0)
    {
        result+=n%10;
        n/=10;
    }
    return result;
}

int main()
{
    memset(number_array,0,sizeof(number_array));
    for(int i=1;i<=1000000;++i)
    {
        int temp=i+digit_sum(i);
        while(temp<=1000000)
        {
            if(number_array[temp]==1)
                break;
            ++number_array[temp];
            temp=temp+digit_sum(temp);
        }
    }
    for(int i=1;i<=1000000;++i)
        if(number_array[i]==0)
            printf("%d\n",i);
    return 0;
}
