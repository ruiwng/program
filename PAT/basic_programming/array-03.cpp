#include  <stdio.h>
#include  <vector>
using namespace std;

int main()
{
	unsigned int num,count;
	while(scanf("%u %u",&num,&count)!=EOF)
	{
		vector<int> num_array(num);
		for(unsigned int i=0;i<num;++i)
		  scanf("%d",&num_array[i]);

		for(unsigned int i=0;i<count;++i)
		{
			for(unsigned int j=0;j<num-1-i;++j)
			 if(num_array[j]>num_array[j+1])
			 {
				 int temp=num_array[j];
				 num_array[j]=num_array[j+1];
				 num_array[j+1]=temp;
			 }
		}
		printf("%d",num_array[0]);
		for(unsigned int i=1;i<num;++i)
			printf(" %d",num_array[i]);
		printf("\n");
	}
	return 0;
}