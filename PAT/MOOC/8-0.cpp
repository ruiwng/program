#include  <stdio.h>

int main()
{
	unsigned int num;
	long int object;
	long int num_array[20];
	while(scanf("%u %ld",&num,&object)!=EOF)
	{
		for(unsigned int i=0;i<num;++i)
			scanf("%ld",&num_array[i]);

		unsigned int j=0;
		for(;j<num;++j)
			if(num_array[j]==object)
				break;

		if(j==num)
			printf("Not Found\n");
		else
			printf("%u\n",j);
	}
	return 0;
}