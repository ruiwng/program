#include  <stdio.h>
#include  <math.h>

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		bool exist=false;
		for(unsigned int i=1;;++i)
		{
			unsigned int temp=sqrt(static_cast<double>(num-i*i));
			if(i>temp)
				break;
			if(i*i+temp*temp==num)
			{
				exist=true;
				printf("%u %u\n",i,temp);
			}
		}
		if(!exist)
			printf("No Solution\n");
	}
	return 0;
}