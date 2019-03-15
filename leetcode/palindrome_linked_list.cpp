#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printNodeList(struct ListNode* head) {
	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

bool isPalindrome(struct ListNode* head) {
	int node_count = 0;
	struct ListNode* p = head;
	while (p != NULL) {
		node_count += 1;
		p = p->next;
	}
	int middle_count = node_count >> 1;
	p = head;
	while (middle_count > 1) {
		p = p->next;
		middle_count -= 1;
	}
	struct ListNode* q = NULL;
	if (p != NULL)
	{
		q = p->next;
		p->next = NULL;
	}
	
	struct ListNode *prev = NULL;
	while (q != NULL) {
		struct ListNode *next = q->next;
		q->next = prev;
		prev = q;
		q = next;
	}
	p = head;
	q = prev;
	printNodeList(p);
	printNodeList(q);
	while (p != NULL && q != NULL) {
		if (p->val != q->val)
			return false;
		p = p->next;
		q = q->next;
	}
	return true;
}

int main() {
	ListNode *n1 = (ListNode*)malloc(sizeof(ListNode));
	n1->val = 1;
	n1->next = NULL;
	ListNode *n2 = (ListNode*)malloc(sizeof(ListNode));
	n2->val = 2;
	n2->next = n1;
	ListNode *n3 = (ListNode*)malloc(sizeof(ListNode));
	n3->val = 2;
	n3->next = n2;
	ListNode *n4 = (ListNode*)malloc(sizeof(ListNode));
	n4->val = 1;
	n4->next = n3;
	bool result = isPalindrome(n4);
	return 0;
}