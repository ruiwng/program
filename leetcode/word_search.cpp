#include  <stdlib.h>
#include  <string.h>

int row,column;
char *record;
char **b;

bool dfs(int x,int y,char *word)
{
	if(*word=='\0')
	    return true;
	if(x<0||x>=row||y<0||y>=column||record[x*column+y]==1||b[x][y]!=*word)
		return false;
	record[x*column+y]=1;
	bool result=dfs(x+1,y,word+1)||dfs(x-1,y,word+1)||dfs(x,y+1,word+1)||dfs(x,y-1,word+1);
    record[x*column+y]=0;
	return result;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
	b=board;
	row=boardRowSize;
	column=boardColSize;
	record=(char*)malloc(row*column*sizeof(char));
	memset(record,0,row*column*sizeof(char));
	bool success=false;
    for(int i=0;!success&&i<boardRowSize;++i)
	{
		for(int j=0;!success&&j<boardColSize;++j)
		{
			if(dfs(i,j,word))
				success=true;
		}
	}
	free(record);
	return success;
}

int main()
{
	char **board=(char**)malloc(3*sizeof(char*));
	board[0]="ABCE";
	board[1]="SFCS";
	board[2]="ADEE";
	bool result=exist(board,3,4,"ABCCED");
	result=exist(board,3,4,"SEE");
	result=exist(board,3,4,"ABCB");
	return 0;
}