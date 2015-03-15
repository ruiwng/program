#include  <stdlib.h>

int **generateMatrix(int n) {
    int **matrix=(int**)malloc(n*sizeof(int*));
	for(int i=0;i<n;++i)
		matrix[i]=(int*)malloc(n*sizeof(int));
    int row_start=0,column_start=0,row_end=n-1,column_end=n-1;
	int num=1;
    while(1)
	{
        for(int i=column_start;i<=column_end;++i)
			matrix[row_start][i]=num++;
		if(++row_start>row_end)
			break;
		for(int i=row_start;i<=row_end;++i)
			matrix[i][column_end]=num++;
		if(--column_end<column_start)
			break;
		for(int i=column_end;i>=column_start;--i)
			matrix[row_end][i]=num++;
		if(--row_end<row_start)
			break;
		for(int i=row_end;i>=row_start;--i)
			matrix[i][column_start]=num++;
		if(++column_start>column_end)
			break;
	}
	return matrix;
}

int main()
{

}
