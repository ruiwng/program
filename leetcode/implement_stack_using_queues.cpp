#include  <queue>
using namespace std;

class Stack {
private:
	queue<int> queue1;
	queue<int> queue2;
public:
    // Push element x onto stack.
    void push(int x) {
        if(!queue2.empty())
			queue2.push(x);
		else
			queue1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(!queue1.empty())
		{
			while(queue1.size() != 1)
			{
				queue2.push(queue1.front());
				queue1.pop();
			}
			queue1.pop();
		}
		else if(!queue2.empty())
		{
			while(queue2.size() != 1)
			{
				queue1.push(queue2.front());
				queue2.pop();
			}
			queue2.pop();
		}
    }

    // Get the top element.
    int top() {
		int result;
         if(!queue1.empty())
		{
			while(queue1.size() != 1)
			{
				queue2.push(queue1.front());
				queue1.pop();
			}
			result = queue1.front();
			queue2.push(queue1.front());
			queue1.pop();
		}
		else if(!queue2.empty())
		{
			while(queue2.size() != 1)
			{
				queue1.push(queue2.front());
				queue2.pop();
			}
			result = queue2.front();
			queue1.push(queue2.front());
			queue2.pop();
		}
		 return result;
    }

    // Return whether the stack is empty.
    bool empty() {
        return queue1.empty() && queue2.empty();
    }
};

int main()
{

}