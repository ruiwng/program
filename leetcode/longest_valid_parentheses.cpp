#include  <stdio.h>
#include  <string>
#include  <stack>
using namespace std;

struct record
{
    int start;
    int end;
    record(int s=0,int e=0):start(s),end(e){
        
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int longest=0;
        int len=s.size();
        stack<int> pos_stack;
        stack<record> record_stack;
        for(int i=0;i<len;++i)
        {
            if(s[i]=='(')
                pos_stack.push(i);
            else
            {
                if(!pos_stack.empty())
                {
                    int t=pos_stack.top();
                    pos_stack.pop();
                    while(!record_stack.empty()&&record_stack.top().start>t)
                        record_stack.pop();
                    while(!record_stack.empty()&&record_stack.top().end==t-1)
                    {
                        t=record_stack.top().start;
                        record_stack.pop();
                    }
                    record_stack.push(record(t,i));
                    if(i-t+1>longest)
                        longest=i-t+1;
                }
            }
        }
        return longest;
    }
};

int main()
{
    const char* str=")()())";
    Solution s;
    int result=s.longestValidParentheses(str);
    printf("%d\n",result);
    return 0;
}
