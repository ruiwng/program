#include  <stdio.h>
#include  <limits.h>

class Solution{
public:
    int atoi(const char *str) {
       long long temp=0;
	   sscanf(str,"%lld",&temp);
	   if(temp>INT_MAX)
	       temp=INT_MAX;
	   else if(temp<INT_MIN)
		   temp=INT_MIN;
	   return temp;
    }
};

int main()
{

}