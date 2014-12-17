#include  <stdio.h>

int main()
{
	int num[4];
	while(scanf("%d %d %d %d",&num[0],&num[1],&num[2],&num[3])!=EOF)
	{
		float sum=num[0]+num[1]+num[2]+num[3];
		float average=sum/4;
		printf("Sum = %.0f; Average = %.1f\n",sum,average);
	}
	return 0;
}