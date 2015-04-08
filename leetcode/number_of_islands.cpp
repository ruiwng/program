
int row,column;
char **g;
int directions[4][2]=
{
	{0,-1},{0,1},{1,0},{-1,0}
};

void dfs(int x,int y)
{
	if(x>=0&&x<row&&y>=0&&y<column&&g[x][y]=='1')
	{
		g[x][y]='2';
		for(int i=0;i<4;++i)
			dfs(x+directions[i][0],y+directions[i][1]);
	}
}

int numIslands(char **grid, int numRows, int numColumns) {
    row=numRows;
	column=numColumns;
	g=grid;
	int num_islands=0;
	for(int i=0;i<numRows;++i)
	{
		for(int j=0;j<numColumns;++j)
		{
			if(grid[i][j]=='1')
			{
				++num_islands;
				dfs(i,j);
			}
		}
	}
	return num_islands;
}

int main()
{
	
}