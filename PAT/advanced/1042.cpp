#include  <stdio.h>

char ch[5]={'S','H','C','D','J'};
int main()
{
	int array[55];
	int array2[2][55];
	int time;
	while(scanf("%d",&time)!=EOF)
	{
		for(int i=1;i<55;i++)
			array2[0][i]=i;
		for(int i=1;i<55;i++)
		{
			int temp;
			scanf("%d",&temp);
			array[i]=temp;
		}
		for(int i=0;i<time;i++)
		{
			for(int j=1;j<55;j++)
			{
				array2[(i+1)%2][array[j]]=array2[i%2][j];
			}
		}
		int m=time%2;
		bool first=true;
		for(int i=1;i<55;i++)
		{
			if(first==true)
				first=false;
			else 
				printf(" ");
			printf("%c",ch[(array2[m][i]-1)/13]);
			printf("%d",(array2[m][i]-1)%13+1);
		}
	}
	return 0;
}