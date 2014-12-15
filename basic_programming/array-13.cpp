#include  <stdio.h>

unsigned int array_info[10][10];
int main()
{
	int num;
	while(scanf("%u",&num)!=EOF)
	{
		int j=0,k=0;
		int i=0;
		while(true)
		{
		   while(i!=num*num&&array_info[j][k]==0&&k<num)
			array_info[j][k++]=++i;
		   if(i==num*num)
			   break;
		   --k;++j;
		   while(i!=num*num&&array_info[j][k]==0&&j<num)
			array_info[j++][k]=++i;
		   if(i==num*num)
			   break;
		   --j;--k;
		   while(i!=num*num&&array_info[j][k]==0&&k>=0)
			 array_info[j][k--]=++i;
		   if(i==num*num)
			   break;
		   ++k;--j;
		   while(i!=num*num&&array_info[j][k]==0&&j>=0)
			array_info[j--][k]=++i;
		   if(i==num*num)
			   break;
		   ++j,++k;
		}

		for(int i=0;i<num;++i)
		{
			for(int j=0;j<num;++j)
				printf("%3d",array_info[i][j]);
			printf("\n");
		}
	}
	return 0;
}