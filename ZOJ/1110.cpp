#include  <stdio.h>

int main()
{
    int s,p,y,j;
    while(scanf("%d%d%d%d",&s,&p,&y,&j)!=EOF)
    {
        int Y=(12-p-y+j)/3;
        int P=Y+p;
        int S=Y+y;
        if(12+j-S-P-Y==1)
        {
            if(S+1-P<=s+1)
                ++S;
            else
                ++P;
        }
         else if(12+j-S-P-Y==2)
        {
            ++S;
            ++P;
        }
        printf("%d %d %d\n",S,P,Y);
    }
    return 0;
}
