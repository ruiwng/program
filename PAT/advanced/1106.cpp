#include  <stdio.h>
#include  <vector>
#include  <queue>
using namespace std;

struct node
{
	int level;
	double price;
	vector<int> children;
};

int main()
{
	int N;
	double p, r;
	while(scanf("%d%lf%lf", &N, &p, &r) != EOF)
	{
		vector<node> node_record(N);
		node_record[0].price = p;
		node_record[0].level = 0;
		for(int i = 0; i < N; ++i)
		{
			int num;
			scanf("%d", &num);
			for(int j = 0; j < num; ++j)
			{
				int child;
				scanf("%d", &child);
				node_record[i].children.push_back(child);
			}
		}
		int lowest = -1;
		double lowest_price;
		int lowest_count = 0;
		queue<int> node_queue;
		node_queue.push(0);
		while(!node_queue.empty())
		{
			int front = node_queue.front();
			node_queue.pop();
			if(lowest != -1 && node_record[front].level == lowest + 1)
				break;
			if(node_record[front].children.empty())
			{
				if(lowest_count == 0)
				{
					lowest = node_record[front].level;
					lowest_price = node_record[front].price;
				}
				++lowest_count;
			}
			else
			{
				vector<int> &children = node_record[front].children;
				int num = children.size();
				for(int i = 0; i < num; ++i)
				{
					node_record[children[i]].price = node_record[front].price * (1 + r / 100);
					node_record[children[i]].level = node_record[front].level + 1;
					node_queue.push(children[i]);
				}
			}
		}
		printf("%.4lf %d\n", lowest_price, lowest_count);
	}
	return 0;
}