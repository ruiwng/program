#include  <stdio.h>
#include  <math.h>
#include  <vector>
#include  <stack>
#include  <queue>
#include  <algorithm>
using namespace std;

struct pos
{
	double x,y,distance;
	int parent;
	pos(double x1=0.0,double y1=0.0):x(x1),y(y1),distance(0.0),parent(-1){}
	bool operator<(const pos& p) const
	{
		return this->distance<p.distance;
	}
};

double distance_array[110][110];

int main()
{
	int n,d;
	while(scanf("%d%d",&n,&d)!=EOF)
	{
		vector<pos> pos_array;
		pos_array.reserve(n+1);
		pos_array.push_back(pos(0.0,0.0));
		for(int i=0;i<n;++i)
		{
			pos p;
			scanf("%lf%lf",&p.x,&p.y);
			p.distance=p.x*p.x+p.y*p.y;
			pos_array.push_back(p);
		}
		sort(pos_array.begin(),pos_array.end());

		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				double d_x=pos_array[j].x-pos_array[i].x;
				double d_y=pos_array[j].y-pos_array[i].y;
				double dis=sqrt(d_x*d_x+d_y*d_y);
			    distance_array[i][j]=distance_array[j][i]=(i==0?(dis-7.5):dis);
			}
		}

		queue<int> node_queue;
		node_queue.push(0);
		pos_array[0].parent=0;
		while(!node_queue.empty())
		{
			int front=node_queue.front();
			if(pos_array[front].x+50<=d||50-pos_array[front].x<=d||pos_array[front].y+50<=d||50-pos_array[front].y<=d)
			{
				int t=front;
				stack<int> path_stack;
				while(t!=0)
				{
					path_stack.push(t);
					t=pos_array[t].parent;
				}
				printf("%d\n",path_stack.size()+1);
				while(!path_stack.empty())
				{
					int top=path_stack.top();
					printf("%.0lf %.0lf\n",pos_array[top].x,pos_array[top].y);
					path_stack.pop();
				}
				break;
			}
			node_queue.pop();
			for(int i=0;i<n;++i)
			{
				if(distance_array[front][i]<=d&&pos_array[i].parent==-1)
				{
					pos_array[i].parent=front;
					node_queue.push(i);
				}
			}
		}
		if(node_queue.empty())
			printf("0\n");
	}
	return 0;
}