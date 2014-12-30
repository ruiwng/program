#include  <stdio.h>

class Solution {
public:
    int jump(int A[], int n) {
        if(n==1)
            return 0;
        int start=0;
        int steps=1;
        int end=0;
        end=start+A[start];
        while(end<n-1)
        {
            if(end>=n-1)
                break;
            int new_end=0;
            while(start<=end)
            {
                if(A[start]+start>new_end)
                    new_end=A[start]+start;
                ++start;
            }
            end=new_end;
            ++steps;
        }
        return steps;
    }
};

int main()
{
    int A[]={
        2,3,1,1,4
    };
    Solution s;
    int result=s.jump(A,4);
    printf("%d\n",result);
    return 0;
}
