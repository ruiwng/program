#include  <stdlib.h>

int *spiralOrder(int **matrix, int numRows, int numColumns) {
    int *r=(int*)malloc(numRows*numColumns*sizeof(int));
	int index=0;
	int row_start=0,column_start=0,row_end=numRows-1,column_end=numColumns-1;
    while(1)
	{
        for(int i=column_start;i<=column_end;++i)
			r[index++]=matrix[row_start][i];
		if(++row_start>row_end)
			break;
		for(int i=row_start;i<=row_end;++i)
			r[index++]=matrix[i][column_end];
		if(--column_end<column_start)
			break;
		for(int i=column_end;i>=column_start;--i)
			r[index++]=matrix[row_end][i];
		if(--row_end<row_start)
			break;
		for(int i=row_end;i>=row_start;--i)
			r[index++]=matrix[i][column_start];
		if(++column_start>column_end)
			break;
	}
	return r;
}

int main()
{
	int matrix[3][3]=
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
    int *r=spiralOrder(matrix,3,3);
	return 0;
}
