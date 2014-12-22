#include  <stdio.h>
#include  <string.h>

int arry[100][100];

int row_traversed[101][101][101];
int column_traversed[101][101][101];

int get_sum(int x1,int y1,int x2,int y2)
{
	int sum=0;
	for(int i=x1;i<=x2;++i)
		for(int j=y1;j<=y2;++j)
			sum+=arry[i][j];
	return sum;
}
//最大矩形各边长的和必大于0！！！
int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		memset(row_traversed,0,sizeof(row_traversed));
		memset(column_traversed,0,sizeof(column_traversed));
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				scanf("%d",&arry[i][j]);
		int sum=arry[0][0];
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
			{
				for(int m=i;m<N;++m)
					for(int n=j;n<N;++n)
					{
						if(column_traversed[j][i][m])
							break;
						if(row_traversed[i][j][n])
							continue;
						int temp=0;
						for(int x=i;x<=m;++x)
							temp+=arry[x][j];
						if(temp<=0)
							break;
						column_traversed[j+1][i][m]=1;
						temp=0;
						for(int x=i;x<=m;++x)
							temp+=arry[x][n];
						if(temp<=0)
							continue;
						column_traversed[n+1][i][m]=1;
						temp=0;
						for(int x=j;x<=n;++x)
							temp+=arry[i][x];
						if(temp<=0)
							continue;
						row_traversed[i+1][j][n]=1;
						for(int x=j;x<=n;++x)
							temp+=arry[m][x];
						if(temp<=0)
							continue;
						row_traversed[m+1][j][n]=1;
						int t=get_sum(i,j,m,n);
						if(t>sum)
							sum=t;
					}
			}
		printf("%d\n",sum);
	}
	return 0;
}