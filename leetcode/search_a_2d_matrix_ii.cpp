
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int column = matrixColSize - 1, row = 0;
	while(row < matrixRowSize && column >= 0)
	{
		if(matrix[row][column] > target)
			--column;
		else if(matrix[row][column] < target)
			++row;
		else
			return true;
	}
	return false;
}

int main()
{

}