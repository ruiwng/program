#include  <vector>
#include  <queue>
using namespace std;

int directions[4][2]=
{
	{1,0},{-1,0},{0,1},{0,-1}
};

struct pos
{
	int x;
	int y;
	pos(int x1=0,int y1=0):x(x1),y(y1){}
};
class Solution
{
public:
	void solve(vector<vector<char> >& board)
	{
		if(board.empty())
			return;
		row=board.size();
		column=board[0].size();
		//change all the 'O' element to 'Y'
		for(int i=0;i<row;++i)
		{
			for(int j=0;j<column;++j)
			    if(board[i][j]=='O')
					board[i][j]='Y';
		}
		for(int i=0;i<row;++i)//search the left and right boundary for the 'Y' element
		{
			if(board[i][0]=='Y')
				traverse(pos(i,0),board);
			if(board[i][column-1]=='Y')
				traverse(pos(i,column-1),board);
		}

		for(int i=0;i<column;++i)//search the top and bottom boundary for the 'Y' element
		{
			if(board[0][i]=='Y')
				traverse(pos(0,i),board);
			if(board[row-1][i]=='Y')
				traverse(pos(row-1,i),board);
		}
		//all 'Y' elements are ones in surrounded regions
		for(int i=0;i<row;++i)
		{
			for(int j=0;j<column;++j)
				if(board[i][j]=='Y')
					board[i][j]='X';
		}

	}
private:
	void traverse(const pos& p,vector<vector<char> >& board)//use queue to find the region not surrounded, meanwhile, change all its elements to 'O' 
	{
		queue<pos> pos_queue;
		pos_queue.push(p);
		board[p.x][p.y]='O';
		while(!pos_queue.empty())
		{
			pos t=pos_queue.front();
			pos_queue.pop();
			for(int j=0;j<4;++j)
			{
				pos temp(t.x+directions[j][0],t.y+directions[j][1]);
				if(temp.x>=0&&temp.x<row&&temp.y>=0&&temp.y<column&&board[temp.x][temp.y]=='Y')
				{
					board[temp.x][temp.y]='O';
					pos_queue.push(temp);
				}
			}
		}
				
	}
private:
	int row;
	int column;
};

int main()
{
	char t[4]={'X','X','X','X'};
	vector<vector<char> > board(4,vector<char>(t,t+4));
	board[1][1]='O';
	board[1][2]='O';
	board[2][2]='O';
	board[3][1]='O';
	Solution s;
	s.solve(board);
	return 0;
}
