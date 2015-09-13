#include  <stdio.h>
#include  <vector>
#include  <queue>
using namespace std;

struct node
{
	int left, right;
	node():left(-1), right(-1){}
};

bool first;
vector<node> node_array;

void in_order(int index)
{
	if(index == -1)
		return;
	in_order(node_array[index].right);
	if(first)
		first = false;
	else
		printf(" ");
	printf("%d", index);
	in_order(node_array[index].left);
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		node_array.assign(n, node());

		vector<int> record(n);
		for(int i = 0; i < n; ++i)
		{
			char temp[2][100];
			scanf("%s%s", temp[0], temp[1]);
			if(temp[0][0] != '-')
			{
				sscanf(temp[0], "%d", &node_array[i].left);
				record[node_array[i].left] = 1;
			}
			if(temp[1][0] != '-')
			{
				sscanf(temp[1], "%d", &node_array[i].right);
				record[node_array[i].right] = 1;
			}
		}
		int root;
		for(int i = 0; i < n; ++i)
		{
			if(record[i] == 0)
			{
				root = i;
				break;
			}
		}

		first = true;
		queue<int> node_queue;
		node_queue.push(root);

		while(!node_queue.empty())
		{
			int front = node_queue.front();
			node_queue.pop();
			if(first)
				first = false;
			else
				printf(" ");
			printf("%d", front);
			if(node_array[front].right != -1)
				node_queue.push(node_array[front].right);
			if(node_array[front].left != -1)
				node_queue.push(node_array[front].left);
		}
		printf("\n");
		first = true;
		in_order(root);
		printf("\n");
	}
	return 0;
}