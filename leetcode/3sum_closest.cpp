#include  <stdlib.h>

int threeSumClosest(int *num, int n, int target) {
     bool first=true;
        bool exist=false;
        int sum=0;
        for(int i=0;!exist&&i<n;++i)
        {
          for(int j=i+1;!exist&&j<n;++j)
          {
             for(int k=j+1;!exist&&k<n;++k)
             {
                    int temp_sum=num[i]+num[j]+num[k];
                    if(first||abs(temp_sum-target)<abs(sum-target))       
                    {
                         first=false;
                         sum=temp_sum;
                         if(sum==target)
                             exist=true;
                    }
             }
          }
        }
        return sum;
}

int main()
{
	
}