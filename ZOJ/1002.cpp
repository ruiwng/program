#include  <stdio.h>

int max_count;
int n;

struct pos
{
	int x,y;
	pos(int x1=0,int y1=0):x(x1),y(y1){}
	pos& operator++()
	{
		if(++y==n)
		{
			y=0;
			++x;
		}
		return *this;
	}
};


void func(char m[5][5],pos p)
{
	if(p.x==n)
	{
		int current_count=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			{
				if(m[i][j]=='A')
					++current_count;
			}
		if(current_count>max_count)
			max_count=current_count;
		return;
	}
	if(m[p.x][p.y]!='X')
	{
		int flag=1;
		for(int i=p.x-1;i>=0;--i)
		{
			if(m[i][p.y]=='A')
			{
				flag=0;
				break;
			}
			else if(m[i][p.y]=='X')
				break;
		}
		if(flag)
		{
			for(int i=p.y-1;i>=0;--i)
			{
				if(m[p.x][i]=='A')
				{
					flag=0;
					break;
				}
				else if(m[p.x][i]=='X')
					break;
			}
		}
		pos q=p;
		++p;
		if(flag)
		{
			m[q.x][q.y]='A';
			func(m,p);
		}
		m[q.x][q.y]='.';
		func(m,p);
	}
	else
	{
		++p;
		func(m,p);
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		max_count=0;
		char matrix[5][5];
		for(int i=0;i<n;++i)
			scanf("%s",matrix[i]);
		func(matrix,pos(0,0));
		printf("%d\n",max_count);
	}
	return 0;
}