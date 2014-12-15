#include  <stdio.h>
#include  <math.h>

int main()
{
	int num1,num2;
	while(scanf("%d %d",&num1,&num2)!=EOF)
	{
		int sum=0;
		for(int i=0;i<num2;++i)
			sum+=num1*(num2-i)*pow(10.0,i);
		printf("%d\n",sum);
	}
	return 0;
}