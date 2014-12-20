#include  <stdio.h>
#include  <string.h>
#include  <algorithm>
using namespace std;

int gcd(int m,int n)
{
    int temp;
    while(n!=0)
    {
        temp=m%n;
        m=n;
        n=temp;
    }
    return m;
}

int main()
{
    char str1[10000];
    while(scanf("%s",str1)!=EOF)
    {
        if(strcmp(str1,"-1")==0)
            break;
        char str2[10000];
        scanf("%s",str2);
        int len1=strlen(str1);
        int len2=strlen(str2);
        int comm_length=0;
        for(int i=-len1;i<len1;++i)
        {
            int current_length=0;
            for(int j=0;j<len2;++j)
            {
                if(i+j<0)
                    continue;
                if(i+j>=len1)
                    break;
                if(str2[j]==str1[i+j])
                    ++current_length;
            }
            if(current_length>comm_length)
                comm_length=current_length;
        }
        int all_length=len1+len2;
        comm_length<<=1;
        printf("appx(%s,%s) = ",str1,str2);
        if(comm_length==0)
            printf("0");
        else if(comm_length==all_length)
            printf("1");
        else
        {
            int temp=gcd(comm_length,all_length);
            printf("%d/%d",comm_length/temp,all_length/temp);
        }
        printf("\n");
    }
    return 0;
}
