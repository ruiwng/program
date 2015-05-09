#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>

int queen_number;
int* place_array;
int distinct_solution;
bool place(int n)
{
	for(int i=1;i<n;++i)
		if(place_array[i]==place_array[n]||abs(i-n)==abs(place_array[i]-place_array[n]))
			return false;
	return true;
}
void n_queen(int n)
{
	for(int i=1;i<=queen_number;++i)
	{
		place_array[n]=i;
		if(place(n))
		{
			if(n<queen_number)
				n_queen(n+1);
			else if(n==queen_number)
				++distinct_solution;
		}
	}
}
int totalNQueens(int n)
{
	place_array=(int*)malloc((n+1)*sizeof(int));
	memset(place_array,0,(n+1)*sizeof(int));
	distinct_solution=0;
	queen_number=n;
	n_queen(1);
	return distinct_solution;
}

int main()
{
	printf("%d %d %d %d\n",totalNQueens(5),totalNQueens(6),totalNQueens(7),totalNQueens(8));
	return 0;
}
