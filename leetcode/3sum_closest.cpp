#include  <stdlib.h>

int threeSumClosest(int *num, int n, int target) {
     bool first=true;
        bool exist=false;
        int sum=0;
        for(unsigned int i=0;i<n;++i)
        {
          for(unsigned int j=i+1;j<n;++j)
          {
             for(unsigned int k=j+1;k<n;++k)
             {
                    int temp_sum=num[i]+num[j]+num[k];
                    if(first||abs(temp_sum-target)<abs(sum-target))       
                    {
                         first=false;
                         sum=temp_sum;
                         if(sum==target)
                         {
                             exist=true;
                             break;
                         }
                    }
             }
             if(exist)
                break;
          }
          if(exist)
             break;
        }
        return sum;
}

int main()
{
	
}