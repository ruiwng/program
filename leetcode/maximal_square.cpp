#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>

#define  min(a, b) (a) <= (b) ? (a) : (b)

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    int length = 0;
	for(int i = 0; i < matrixRowSize - length; ++i)
	{
		for(int j = 0; j < matrixColSize - length; ++j)
		{
			int temp = min(matrixRowSize - i, matrixColSize - j);
			for(int k = i; k < i + temp; ++k)
			{
				for(int m = j; m < j + temp; ++m)
				{
					if(matrix[k][m] == '0')
					{
						temp = m - j;
						break;
					}
				}
			}
			if(temp > length)
				length = temp;
		}
	}
	return length * length;
}

int main()
{
	char **matrix = (char **)malloc(sizeof(char *) * 4);
	for(int i = 0; i < 4; ++i)
	   matrix[i] = (char *)malloc(sizeof(char) * 5);
	strcpy(matrix[0], "10100");
	strcpy(matrix[1], "10111");
	strcpy(matrix[2], "11111");
	strcpy(matrix[3], "10010");
	int area = maximalSquare(matrix, 4, 5);
	printf("%d\n", area);

	return 0;
}