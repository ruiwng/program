#include <stack>
using namespace std;

class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        mStack.push(val);
        if(mMinStack.empty()) {
            mMinStack.push(val);
        } else {
            mMinStack.push(min(val, mMinStack.top()));
        }
    }
    
    void pop() {
        mStack.pop();
        mMinStack.pop();
    }
    
    int top() {
        return mStack.top();
    }
    
    int getMin() {
        return mMinStack.top();
    }
private:
    stack<int> mStack;
    stack<int> mMinStack;
};

int main() {
    
}
