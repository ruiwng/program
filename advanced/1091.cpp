/*
#include  <stdio.h>

int arr[61][1290][130];

struct pos
{
	int x,y,z;
	pos(int x1=0,int y1=0,int z1=0):x(x1),y(y1),z(z1){}
};

int M,N,L,T;

void traverse(const pos& p,int& num)
{
	if(p.x>=0&&p.x<L&&p.y>=0&&p.y<M&&p.z>=0&&p.z<N)
	{
		if(arr[p.x][p.y][p.z]==1)
		{
			++num;
			++arr[p.x][p.y][p.z];
			traverse(pos(p.x+1,p.y,p.z),num);
			traverse(pos(p.x-1,p.y,p.z),num);
			traverse(pos(p.x,p.y+1,p.z),num);
			traverse(pos(p.x,p.y-1,p.z),num);
			traverse(pos(p.x,p.y,p.z+1),num);
			traverse(pos(p.x,p.y,p.z-1),num);
		}
	}
}

int main()
{
	while(scanf("%d %d %d %d",&M,&N,&L,&T)!=EOF)
	{
		for(int i=0;i<L;++i)
		{
			for(int j=0;j<M;++j)
			{
				for(int k=0;k<N;++k)
					scanf("%d",&arr[i][j][k]);
			}
		}
		int all_counts=0;
		for(int i=0;i<L;++i)
		{
			for(int j=0;j<M;++j)
			{
				for(int k=0;k<N;++k)
				{
					if(arr[i][j][k]==1)
					{
						int num=0;
						traverse(pos(i,j,k),num);
						if(num>=T)
						   all_counts+=num;
					}
				}
			}
		}
		printf("%d\n",all_counts);
	}
	return 0;
}*/


#include  <stdio.h>
#include  <stack>
using namespace std;

int arr[60][1286][128];

int direction[6][3]=
{
	{-1,0,0},
	{1,0,0},
	{0,-1,0},
	{0,1,0},
	{0,0,-1},
	{0,0,1}
};

struct pos
{
	int x,y,z;
	pos(int x1=0,int y1=0,int z1=0):x(x1),y(y1),z(z1){}
};

int M,N,L,T;


int main()
{
	while(scanf("%d %d %d %d",&M,&N,&L,&T)!=EOF)
	{
		for(int i=0;i<L;++i)
		{
			for(int j=0;j<M;++j)
			{
				for(int k=0;k<N;++k)
					scanf("%d",&arr[i][j][k]);
			}
		}
		int all_counts=0;
		for(int i=0;i<L;++i)
		{
			for(int j=0;j<M;++j)
			{
				for(int k=0;k<N;++k)
				{
					if(arr[i][j][k]==1)
					{
						int num=0;
						arr[i][j][k]=2;
						stack<pos> pos_stack;
						pos_stack.push(pos(i,j,k));
						while(!pos_stack.empty())
						{
							pos t=pos_stack.top();
							pos_stack.pop();
							++num;
							for(int x=0;x<6;++x)
							{
								pos temp(t.x+direction[x][0],t.y+direction[x][1],t.z+direction[x][2]);
								if(temp.x>=0&&temp.x<L&&temp.y>=0&&temp.y<M&&temp.z>=0&&temp.z<N&&arr[temp.x][temp.y][temp.z]==1)
								{
									arr[temp.x][temp.y][temp.z]=2;
									pos_stack.push(temp);
								}
							}
						}
						if(num>=T)
						   all_counts+=num;
					}
				}
			}
		}
		printf("%d\n",all_counts);
	}
	return 0;
}