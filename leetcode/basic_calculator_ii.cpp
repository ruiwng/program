#include  <string>
#include  <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
		s.push_back('#');
		int len = s.length();
		int current_value = 0;
		stack<string> str_stack;
		for(int i = 0; ; ++i)
		{
			if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '#')
			{
				while(!str_stack.empty())
				{
					if((str_stack.top() == "-" || str_stack.top() == "+") && (s[i] == '*' || s[i] == '/'))
						break;
					string oper = str_stack.top();
					str_stack.pop();
					int m;
					sscanf(str_stack.top().c_str(), "%d", &m);
					str_stack.pop();
					switch(oper[0])
					{
					case '+':
						current_value = m + current_value;
						break;
					case '-':
						current_value = m - current_value;
						break;
					case '*':
						current_value = m * current_value;
						break;
					case '/':
						current_value = m / current_value;
						break;
					}
				}
				if(s[i] == '#')
					break;
				char temp[100];
				sprintf(temp, "%d", current_value);
				str_stack.push(temp);
				current_value = 0;
				str_stack.push(string(1, s[i]));
			}
			else if(s[i] >= '0' && s[i] <= '9')
				current_value = current_value * 10 + s[i] - '0';
		}
		return current_value;
    }
};

int main()
{
	Solution s;
	int result = s.calculate("3+2*2");
	result = s.calculate(" 3/2 ");
	result = s.calculate(" 3+5 / 2 ");
	return 0;
}