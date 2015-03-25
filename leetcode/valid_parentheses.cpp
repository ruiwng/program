#include  <string>
#include  <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int length=s.length();
		stack<char> left_parent_stack;
		for(int i=0;i<length;++i)
		{
			switch(s[i])
			{
			case '(':
			case '{':
			case '[':
				left_parent_stack.push(s[i]);
				break;
			case ')':
				if(!left_parent_stack.empty()&&left_parent_stack.top()=='(')
					left_parent_stack.pop();
				else
					return false;
				break;
			case '}':
				if(!left_parent_stack.empty()&&left_parent_stack.top()=='{')
					left_parent_stack.pop();
				else
					return false;
				break;
			case ']':
				if(!left_parent_stack.empty()&&left_parent_stack.top()=='[')
					left_parent_stack.pop();
				else
					return false;
				break;
			}
		}
		return left_parent_stack.empty();
    }
};

int main()
{
	
}