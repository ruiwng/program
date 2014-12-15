#include  <stdio.h>

int main()
{
	unsigned int day;
	while(scanf("%u",&day)!=EOF)
	{
		unsigned int num=1;
		for(unsigned int i=1;i<day;++i)
			num=(num+1)*2;
		printf("%u\n",num);
	}
	return 0;
}