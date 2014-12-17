#include  <stdio.h>
#include  <vector>
using namespace std;

int main()
{
	vector<long int> num_array[2];
	for(unsigned int i=0;i<2;i++)
	{
		unsigned int number;
		scanf("%u",&number);
		num_array[i].reserve(number);
		for(unsigned int j=0;j<number;j++)
		{
			long int temp;
			scanf("%ld",&temp);
			num_array[i].push_back(temp);
		}
	}
	unsigned int num=(num_array[0].size()+num_array[1].size()-1)/2;
	int index=-1;
	unsigned int index1=0,index2=0;
	while(index1<num_array[0].size()&&index2<num_array[1].size())
	{
		  if(num_array[0][index1]<=num_array[1][index2])
		  {
			 ++index1;
			 if(++index==num)
			 {
				printf("%ld\n",num_array[0][index1-1]);
				break;
			 }
		  }
		  else
		  {
			 ++index2;
			 if(++index==num)
			 {
				printf("%ld\n",num_array[1][index2-1]);
				break;
			 }
		  }
	}
	if(index<num&&index1<num_array[0].size())
		printf("%ld\n",num_array[0][index1+num-index-1]);
	if(index<num&&index2<num_array[1].size())
		printf("%ld\n",num_array[1][index2+num-index-1]);
	return 0;
}