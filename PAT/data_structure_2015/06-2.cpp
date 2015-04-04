#include  <stdio.h>
#include  <math.h>
#include  <vector>
#include  <queue>
using namespace std;

struct pos
{
	double x;
	double y;
	bool traversed;
	pos(double x1=0,double y1=0):x(x1),y(y1),traversed(false){}
};

double distance_array[110][110];

int main()
{
	int num;
	double max_distance;
	while(scanf("%d%lf",&num,&max_distance)!=EOF)
	{
		vector<pos> pos_array;
		pos_array.reserve(num+1);
		pos_array.push_back(pos(0.0,0.0));
		for(int i=0;i<num;++i)
		{
			pos p;
			scanf("%lf%lf",&p.x,&p.y);
			pos_array.push_back(p);
		}
		for(int i=0;i<=num;++i)
		{
			for(int j=i+1;j<=num;++j)
			{
				double temp1=pos_array[j].x-pos_array[i].x;
				double temp2=pos_array[j].y-pos_array[i].y;
				double d=sqrt(temp1*temp1+temp2*temp2);
				if(i==0)
					d-=7.5;
				distance_array[i][j]=distance_array[j][i]=d;
			}
		}
		queue<int> node_queue;
		node_queue.push(0);
		pos_array[0].traversed=true;
		bool success=false;
		while(!node_queue.empty())
		{
			int front=node_queue.front();
			node_queue.pop();
			if(pos_array[front].x<=-50+max_distance||pos_array[front].x>=50-max_distance||
				pos_array[front].y<=-50+max_distance||pos_array[front].y>=50-max_distance)
			{
				success=true;
				break;
			}
			for(int i=1;i<=num;++i)
			{
				if(!pos_array[i].traversed&&distance_array[front][i]<=max_distance)
				{
					pos_array[i].traversed=true;
					node_queue.push(i);
				}
			}
		}
		printf("%s\n",success?"Yes":"No");
	}
	return 0;
}