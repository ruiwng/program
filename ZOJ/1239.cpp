#include  <stdio.h>
#include  <math.h>
#include  <vector>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            int num;
            scanf("%d",&num);
             vector<int> hanoi(num,0);
             int j=1;
             while(true)
            {
               int k=0;
               for(;k<num;++k)
               {
                  if(hanoi[k]==0||(pow(static_cast<int>(sqrt(hanoi[k]+j)),2)==hanoi[k]+j))
                  {
                    hanoi[k]=j;
                    break;
                  }
               }
               if(k==num)
               {
                  printf("%d\n",j-1);
                  break;
               }
               ++j;
            }
        }    
    }
    return 0;
}
