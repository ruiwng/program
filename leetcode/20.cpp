#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                char_stack.push(s[i]);
            } else {
                if(char_stack.empty()) {
                    return false;
                }
                if((s[i] == ')' && char_stack.top() == '(') ||
                   (s[i] == '}' && char_stack.top() == '{') ||
                   (s[i] == ']' && char_stack.top() == '[')) {
                    char_stack.pop();
                } else {
                    return false;
                }
            }
        }
        return char_stack.empty();
    }
};

int main() {
    
}
