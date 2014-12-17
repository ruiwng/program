#include  <stdio.h>
#include  <stdlib.h>

int main()
{
	
		bool first=true;
		int number=0;
		int n[10];
		scanf("%d %d %d %d %d %d %d %d %d %d",&n[0],&n[1],&n[2],&n[3],&n[4],&n[5],&n[6],&n[7],&n[8],&n[9]);
		for(int i=0;i<10;i++)
		{
			if(n[i]==0)
				continue;
			if(first==false)
			{
				for(int m=1;m<=n[i];m++)
				  printf("%d",i);
				continue;
			}
		    if(i==0)
			{
				number=n[i];
				continue;
			}
			if(first==true)
			{
				first=false;
				printf("%d",i);
				for(int m=1;m<=number;m++)
					printf("0");
				for(int m=1;m<=n[i]-1;m++)
					printf("%d",i);
			}
		}
		printf("\n");
	return 0;
}