void rotate(int **matrix, int n) {
    if(n==0)
       return;
    int pos=0;
		--n;
		while(pos<n)
		{
			for(int i=pos;i<n;++i)
			{
				int temp=matrix[pos][i];
				matrix[pos][i]=matrix[n-i+pos][pos];
				matrix[n-i+pos][pos]=matrix[n][n-i+pos];
				matrix[n][n-i+pos]=matrix[i][n];
				matrix[i][n]=temp;
			}
			++pos;
			--n;
		}
}

int main()
{
	
}