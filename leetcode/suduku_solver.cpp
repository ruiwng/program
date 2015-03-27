#include  <stdlib.h>
#include  <string.h>

struct pos
{
	int x;
	int y;
};

int row_record[9][10];
int column_record[9][10];
int square_record[9][10];

bool add_record(int row,int column,int n)
{
	if(row_record[row][n]>=1)
		return false;
	if(column_record[column][n]>=1)
		return false;
	if(square_record[row/3*3+column/3][n]>=1)
		return false;
	++row_record[row][n];
	++column_record[column][n];
	++square_record[row/3*3+column/3][n];
	return true;
}

void remove_record(int row,int column,int n)
{
	--row_record[row][n];
	--column_record[column][n];
	--square_record[row/3*3+column/3][n];
}

void solveSudoku(char board[9][10]) {
	 memset(row_record,0,sizeof(row_record));
	 memset(column_record,0,sizeof(column_record));
	 memset(square_record,0,sizeof(square_record));
	 struct pos *p_array=(struct pos*)malloc(sizeof(struct pos)*81);
	 int num=0;
	 for(int i=0;i<9;++i)
	  for(int j=0;j<9;++j)
	  {
		  if(board[i][j]=='.')
		  {
			  p_array[num].x=i;
			  p_array[num].y=j;
			  ++num;
			  board[i][j]='0';
		  }
		  else
		      add_record(i,j,board[i][j]-'0');
	  }
	  int index=0;
	  while(index>=0)
	  {
		  int current_x=p_array[index].x;
		  int current_y=p_array[index].y;
		  remove_record(current_x,current_y,board[current_x][current_y]-'0');
		  ++board[current_x][current_y];
		  while(board[current_x][current_y]<='9'&&!add_record(current_x,current_y,board[current_x][current_y]-'0'))
		      ++board[current_x][current_y];
		  if(board[current_x][current_y]>'9')
		  {
			  board[current_x][current_y]='0';
			  --index;
		  }
		  else if(++index==num)
			  break;
	  }
}

int main()
{
	char sudu[9][10]=
	{
		"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."
	};
	solveSudoku(sudu);
	return 0;
}