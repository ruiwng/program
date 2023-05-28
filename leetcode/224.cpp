#include <string>
#include <stack>
using namespace std;

struct Element {
    Element(int v): is_value(true), value(v), op(0) {}
    Element(char o): is_value(false), value(0), op(o) {}
    
public:
    bool is_value;
    int value;
    char op;
};

class Solution {
    bool is_operator(char c) {
        return c == '+' || c == '-' || c == '(' || c == ')';
    }
    
    bool is_space(char c) {
        return c == ' ';
    }
    
    bool is_number(char c) {
        return c >= '0' && c <= '9';
    }
    
    int do_eval(int v1, int v2, char op) {
        if(op == '+') {
            return v1 + v2;
        } else {
            return v1 - v2;
        }
    }
    int evaluate(stack<Element>& evaluations) {
        int current_value = 0;
        char current_op = ' ';
        while(!evaluations.empty()) {
            auto top = evaluations.top();
            evaluations.pop();
            if(top.is_value) {
                if(current_op == ' ') {
                    current_value = top.value;
                } else {
                    current_value = do_eval(current_value, top.value, current_op);
                }
            } else {
                current_op = top.op;
            }
        }
        return current_value;
    }
public:
    int calculate(string s) {
        int len = static_cast<int>(s.length());
        int index = 0;
        stack<Element> element_stack;
        while(true) {
            while(index < len && is_space(s[index])) {
                ++index;
            }
            if(index >= len) {
                break;
            }
            if(is_operator(s[index])) {
                if(s[index] != ')') {
                    element_stack.push(Element(s[index]));
                } else {
                    stack<Element> evaluation_stack;
                    while(true) {
                        auto top = element_stack.top();
                        element_stack.pop();
                        if(!top.is_value && top.op == '(') {
                            break;
                        }
                        evaluation_stack.push(top);
                    };
                    int value = evaluate(evaluation_stack);
                    printf("%d\n", value);
                    element_stack.push(value);
                }
                ++index;
            } else {
                int num = 0;
                while(is_number(s[index])) {
                    num = num * 10 + (s[index] - '0');
                    ++index;
                }
                element_stack.push(Element(num));
            }
        }
        stack<Element> evaluation_stack;
        while(!element_stack.empty()) {
            evaluation_stack.push(element_stack.top());
            element_stack.pop();
        }
        int value = evaluate(evaluation_stack);
        return value;
    }
};

int main() {
    Solution s;
    int r = s.calculate("2147483647");
    return 0;
}
