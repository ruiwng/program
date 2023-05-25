#include <vector>
#include <string>
#include <stack>
using namespace std;


class Solution {
    int doEvaluation(int x, int y, const string& op) {
        if(op == "+") {
            return x + y;
        } else if(op == "-") {
            return x - y;
        } else if(op == "*") {
            return x * y;
        } else {
            return x / y;
        }
    }
    bool isOperator(const string& op) {
        return op == "+" || op == "-" || op == "*" || op == "/";
    }
public:
    
    int evalRPN(vector<string>& tokens) {
        stack<int> operand_stack;
        for(auto i = 0; i < tokens.size(); ++i) {
            if(!isOperator(tokens[i])) {
                operand_stack.push(stoi(tokens[i]));
            } else {
                int y = operand_stack.top();
                operand_stack.pop();
                int x = operand_stack.top();
                operand_stack.pop();
                operand_stack.push(doEvaluation(x, y, tokens[i]));
            }
        }
        return operand_stack.top();
    }
};

int main() {
    Solution s;
    vector<string> tokens({"10","6","9","3","+","-11","*","/","*","17","+","5","+"});
    int r = s.evalRPN(tokens);
    return 0;
}
