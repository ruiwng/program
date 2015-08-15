#include  <string>
#include  <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<string> str_stack;
		int len = s.length();
		string oper;
		bool flag = false;
		int current_value = 0;
		for(int i = 0; i < len; ++i)
		{
			if(s[i] == '(')
				str_stack.push("(");
			else if(s[i] == ')' || s[i] == '+' || s[i] == '-')
			{
				bool first = true;
				if(!flag)
				{
					string m = str_stack.top();
					str_stack.pop();
					sscanf(m.c_str(), "%d", &current_value);
				}
				flag = false;
				while(!str_stack.empty())
				{
					if(str_stack.top() == "(")
					{
						if(s[i] == ')' && first)
						{
							first = false;
							str_stack.pop();
							continue;
						}
						else
						    break;
					}
					oper = str_stack.top();
					str_stack.pop();
					string num = str_stack.top();
					str_stack.pop();
					int m;
					sscanf(num.c_str(), "%d", &m);
					if(oper == "+")
						current_value = m + current_value;
					else
						current_value = m - current_value;
				}
				char temp[100];
				sprintf(temp, "%d", current_value);
				str_stack.push(temp);
				if(s[i] == '+')
					str_stack.push("+");
				else if(s[i] == '-')
					str_stack.push("-");
				current_value = 0;
			}
			else if(s[i] >= '0' && s[i] <= '9')
			{
				flag = true;
				current_value = current_value * 10 + s[i] - '0';
			}
		}
		if(!flag)
		   sscanf(str_stack.top().c_str(), "%d", &current_value);
		else if(!str_stack.empty())
		{
			oper = str_stack.top();
			str_stack.pop();
			int m;
			sscanf(str_stack.top().c_str(), "%d", &m);
			str_stack.pop();
			if(oper == "+")
				current_value = m + current_value;
			else
				current_value = m - current_value;
		}
		return current_value;
    }
};

int main()
{
	char temp[100];
	strcpy(temp, "0");
	Solution s;
	int result = s.calculate(temp);
	strcpy(temp, "1 + 1");
	result = s.calculate(temp);
	strcpy(temp, "2-1 + 2 ");
	result = s.calculate(temp);
	return 0;
}