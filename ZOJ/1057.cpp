#include  <stdio.h>

int arry[2][20];

int main()
{
	int n;
	int number=0;
	while(scanf("%d",&n)!=EOF&&n)
	{
		if(number++>0)
			printf("\n");
		for(int i=0;i<2;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&arry[i][j]);

		int a_points=0,b_points=0;
		for(int i=0;i<n;++i)
		{
			if(arry[0][i]==arry[1][i])
				continue;
			else if(arry[0][i]-arry[1][i]>1)
				a_points+=arry[0][i];
			else if(arry[1][i]-arry[0][i]>1)
				b_points+=arry[1][i];
			else if(arry[0][i]-arry[1][i]==1)
			{
				if(arry[0][i]==2)
					b_points+=2*(arry[0][i]+arry[1][i]);
				else
					b_points+=arry[0][i]+arry[1][i];
			}
			else if(arry[1][i]-arry[0][i]==1)
			{
				if(arry[1][i]==2)
					a_points+=2*(arry[0][i]+arry[1][i]);
				else
					a_points+=arry[0][i]+arry[1][i];
			}
		}
		printf("A has %d points. B has %d points.\n",a_points,b_points);
	}
	return 0;
}