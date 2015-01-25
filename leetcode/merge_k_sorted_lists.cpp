#include  <vector>
#include  <queue>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct cmp_func
{
	bool operator()(const ListNode* lhs,const ListNode* rhs) const
	{
		return lhs->val>rhs->val;
	}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		priority_queue<ListNode*,deque<ListNode*>,cmp_func> node_queue;
		ListNode* result=new ListNode(0);
		ListNode* p=result;
		int len=lists.size();
		for(int i=0;i<len;++i)
			if(lists[i]!=NULL)
			   node_queue.push(lists[i]);
		while(!node_queue.empty())
		{
			p->next=node_queue.top();
			node_queue.pop();
			p=p->next;
			if(p->next!=NULL)
				node_queue.push(p->next);
		}
		return result->next;
    }
};

int main()
{

}