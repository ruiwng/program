#include  <stdio.h>

int main()
{
	bool first=true;
	int number=0;
	int n[10];
	while(scanf("%d %d %d %d %d %d %d %d %d %d",&n[0],&n[1],&n[2],&n[3],&n[4],&n[5],&n[6],&n[7],&n[8],&n[9])!=EOF)
	{
		for(int i=1;i<10;++i)
		{
			if(n[i]!=0)
			{
				printf("%d",i);
				--n[i];
				break;
			}
		}
		for(int i=0;i<10;++i)
		{
			for(int j=0;j<n[i];++j)
				printf("%d",i);
		}
		printf("\n");
	}	
	return 0;
}
