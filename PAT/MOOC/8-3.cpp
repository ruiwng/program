#include  <stdio.h>

int main()
{
	unsigned int num_array[10];
	for(unsigned int i=0;i<10;++i)
		scanf("%u",&num_array[i]);

	for(unsigned int i=1;i<10;++i)
		if(num_array[i]!=0)
		{
			printf("%u",i);
			--num_array[i];
			break;
		}
	for(unsigned int i=0;i<10;++i)
		for(unsigned int j=0;j<num_array[i];++j)
			printf("%u",i);
	printf("\n");
	return 0;
}