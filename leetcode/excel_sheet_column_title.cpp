#include  <stdio.h>
#include  <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while(n!=0)
        {
            result.insert(result.begin(),1,(n-1)%26+'A');
            n=(n-1)/26;
        }
        return result;
    }
};

int main()
{
    Solution s;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%s\n",s.convertToTitle(n).c_str());
    }
    return 0;
}
