#include  <stdio.h>
#include  <string.h>

struct square
{
	int top;
	int right;
	int bottom;
	int left;
	int number;
	square(int t=0,int r=0,int b=0,int l=0,int n=1):top(t),right(r),bottom(b),left(l),number(n){}
	bool operator==(const square& s) const
	{
		return this->top==s.top&&this->right==s.right&&this->bottom==s.bottom&&this->left==s.left;
	}
};

square square_arry[26];
int n;
int sum;
int all_number;
int places[5][5];

struct pos
{
	int x;
	int y;
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
	pos& operator--()
	{
		if(--y==-1)
		{
			y=n-1;
			--x;
		}
		return *this;
	}
	bool operator<(const pos& p) const
	{
		return x<p.x||(x==p.x&&y<p.y);
	}
};

bool is_legal(const pos& p)
{
	if(square_arry[places[p.x][p.y]].number==0)
		return false;
	if(p.x>0)
	{
		if(square_arry[places[p.x-1][p.y]].bottom!=square_arry[places[p.x][p.y]].top)
			return false;
	}
	if(p.y>0)
	{
		if(square_arry[places[p.x][p.y-1]].right!=square_arry[places[p.x][p.y]].left)
			return false;
	}
	return true;
}

bool back_tracing()
{
	pos p;
	while(p.x>=0)
	{
		++square_arry[places[p.x][p.y]].number;
		++places[p.x][p.y];
		while(places[p.x][p.y]<=all_number&&!is_legal(p))
		   ++places[p.x][p.y];

		if(places[p.x][p.y]==all_number+1)
		{
			places[p.x][p.y]=0;
			--p;
		}
		else
		{
			--square_arry[places[p.x][p.y]].number;
			++p;
			if(p.x>=n)
				return true;
		}
	}
	return false;
}

int main()
{
	int case_count=0;
	while(scanf("%d",&n)!=EOF&&n)
	{
		sum=n*n;
		all_number=0;
		for(int i=1;i<=sum;++i)
		{
			square temp;
			scanf("%d%d%d%d",&temp.top,&temp.right,&temp.bottom,&temp.left);
			int j;
			for(j=1;j<=all_number;++j)
			{
				if(square_arry[j]==temp)
				{
					++square_arry[j].number;
					break;
				}
			}
			if(j>all_number)
				square_arry[++all_number]=temp;
		}

		memset(places,0,sizeof(places));
		++case_count;
		printf("%sGame %d: ",case_count!=1?"\n":"",case_count);
		if(back_tracing())
			printf("Possible\n");
		else
			printf("Impossible\n");
	}
	return 0;
}