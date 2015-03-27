#include  <vector>
#include  <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int length=num.size();
        if(length==0||length==1)
           return;
        int maxElement=num[length-1];
        int pos=length-1;
        int i;
        for(i=length-2;i>=0;--i)
        {
            if(num[i]>=maxElement)
            {
                maxElement=num[i];
                continue;
            }
            else if(num[i]<maxElement)
            {
                sort(&num[i+1],&num[length]);
                int j=i+1;
                while(num[j]<=num[i])
                  ++j;
                int temp=num[j];
                num[j]=num[i];
                num[i]=temp;
                sort(&num[i+1],&num[length]);
                break;
            }
        }
        if(i==-1)
           sort(num.begin(),num.end());
    }
};

int main()
{
	
}