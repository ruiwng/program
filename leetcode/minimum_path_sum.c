int minPathSum(int **grid, int nRows, int nCols) {
    	for(int i=0;i<nRows;++i)
			grid[i][0]+=grid[i-1][0];
		for(int i=0;i<nCols;++i)
			grid[0][i]+=grid[0][i-1];
		for(int i=1;i<nRows;++i)
		{
			for(int j=1;j<nCols;++j)
				grid[i][j]+=grid[i][j-1]<=grid[i-1][j]?grid[i][j-1]:grid[i-1][j];
		}
		return grid[nRows-1][nCols-1];
}
