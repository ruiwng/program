#include  <stdio.h>
#include  <queue>
using namespace std;

struct pos
{
	int x;
	int y;
	pos(int x1=0,int y1=0):x(x1),y(y1){}
};

char grid[20][20];

int directions[8][2]=
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1},
	{-1,-1},
	{-1,1},
	{1,-1},
	{1,1},
};

int main()
{
	int row,column;
	pos p;
	while(scanf("%d%d%d%d",&row,&column,&p.x,&p.y)!=EOF)
	{
		if(row==0&&column==0&&p.x==0&&p.y==0)
			break;
		--p.x;
		--p.y;
		for(int i=0;i<row;++i)
			scanf("%s",grid[i]);

		queue<pos> pos_queue;
		pos_queue.push(p);
		int perimeter=0;
		grid[p.x][p.y]='Y';
		while(!pos_queue.empty())
		{
			pos temp=pos_queue.front();
			pos_queue.pop();
			for(int i=0;i<4;++i)
			{
				pos t(temp.x+directions[i][0],temp.y+directions[i][1]);
				if(t.x>=0&&t.x<row&&t.y>=0&&t.y<column)
				{
					if(grid[t.x][t.y]=='X')
					{
						pos_queue.push(t);
						grid[t.x][t.y]='Y';
					}
					else if(grid[t.x][t.y]=='.')
						++perimeter;
				}
				else
					++perimeter;
			}
			for(int i=4;i<8;++i)
			{
				pos t(temp.x+directions[i][0],temp.y+directions[i][1]);
				if(t.x>=0&&t.x<row&&t.y>=0&&t.y<column&&grid[t.x][t.y]=='X')
				{
						pos_queue.push(t);
						grid[t.x][t.y]='Y';
				}
			}
		}
		printf("%d\n",perimeter);
	}
	return 0;
}