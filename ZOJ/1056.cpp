#include  <stdio.h>
#include  <string.h>
#include  <deque>
using namespace std;

int board[51][51];

struct pos
{
	int x,y;
	pos(int x1=0,int y1=0):x(x1),y(y1){}
};
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		char str[110];
		scanf("%s",str);
		deque<pos> worm_pos;
		memset(board,0,sizeof(board));
		for(int i=11;i<=30;++i)
		{
			board[25][i]=1;
			worm_pos.push_back(pos(25,i));
		}
		bool fail=false;
		for(int i=0;i<n;++i)
		{
			board[worm_pos.front().x][worm_pos.front().y]=0;
			worm_pos.pop_front();
			pos temp(worm_pos.back());
			switch(str[i])
			{
			case 'E':
				++temp.y;
				break;
			case 'W':
				--temp.y;
				break;
			case 'N':
			    --temp.x;
				break;
			case 'S':
				++temp.x;
				break;
			}
			if(temp.x<1||temp.x>50||temp.y<1||temp.y>50)
			{
				fail=true;
				printf("The worm ran off the board on move %d.\n",i+1);
				break;
			}
			else if(board[temp.x][temp.y]==1)
			{
				fail=true;
				printf("The worm ran into itself on move %d.\n",i+1);
				break;
			}
			board[temp.x][temp.y]=1;
			worm_pos.push_back(temp);
		}
		if(!fail)
			printf("The worm successfully made all %d moves.\n",n);
	}
	return 0;
}