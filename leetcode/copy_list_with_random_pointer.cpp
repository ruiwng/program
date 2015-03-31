#include  <unordered_map>
using namespace std;

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
	   RandomListNode *i=head;
	   RandomListNode *h=new RandomListNode(0);
	   RandomListNode *p=h;
	   while(i!=NULL)
	   {
		   p->next=new RandomListNode(i->label);
		   pointer_map.insert(make_pair(i,p->next));
		   p=p->next;
		   i=i->next;
	   }
	   i=head;
	   p=h->next;
	   while(i!=NULL)
	   {
		   p->random=pointer_map[i->random];
		   p=p->next;
		   i=i->next;
	   }
	   return h->next;
    }
private:
	unordered_map<RandomListNode*,RandomListNode*> pointer_map;
};

int main()
{
	Solution s;
	RandomListNode *p=new RandomListNode(-1);
	RandomListNode *q=s.copyRandomList(p);
	return 0;
}