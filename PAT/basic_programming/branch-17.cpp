#include  <stdio.h>

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		unsigned int A=0,B=0,C=0,D=0,E=0;
		for(unsigned int i=0;i<num;++i)
		{
			unsigned int temp;
			scanf("%u",&temp);
			if(temp>=90)
				++A;
			else if(temp<90&&temp>=80)
				++B;
			else if(temp<80&&temp>=70)
				++C;
			else if(temp<70&&temp>=60)
				++D;
			else 
				++E;
		}
		printf("%u %u %u %u %u\n",A,B,C,D,E);
	}
	return 0;
}