#include  <stdio.h>
#include  <vector>
using namespace std;
int main()
{
	unsigned int number_programmers,number_mice;
	while(scanf("%u %u",&number_programmers,&number_mice)!=EOF)
	{
		vector<unsigned int> weight_array(number_programmers);
		for(unsigned int i=0;i<number_programmers;++i)
			scanf("%u",&weight_array[i]);
		vector<unsigned int> play_order(number_programmers);
		for(unsigned int i=0;i<number_programmers;++i)
			scanf("%u",&play_order[i]);
		vector<unsigned int> weight_sets(number_programmers);

		unsigned int already_sets=0;
		while(already_sets<number_programmers)
		{
		   vector<unsigned int> play_order_temp;
		   if(play_order.size()==1)
		   {
			   weight_sets[play_order[0]]=1;
			   break;
		   }
		   vector<unsigned int> temp_array;
		   for(unsigned int i=0;i<play_order.size();i+=number_mice)
		   {
			 unsigned int max_temp=play_order[i];
			 for(unsigned int j=1;j<number_mice;j++)
			 {
				 if(i+j>=play_order.size())
					 break;
				 already_sets++;
				 if(weight_array[play_order[i+j]]>weight_array[max_temp])
				 {
					 temp_array.push_back(max_temp);
					 max_temp=play_order[i+j];				 
				 }
				 else
					 temp_array.push_back(play_order[i+j]);
			 }
			 play_order_temp.push_back(max_temp);
		   }
		   unsigned int temp_variable=number_programmers-already_sets+1;
		   for(unsigned int i=0;i<temp_array.size();++i)
			   weight_sets[temp_array[i]]=temp_variable;
		   play_order.swap(play_order_temp);
		}
		printf("%u",weight_sets[0]);
		for(unsigned int i=1;i<number_programmers;++i)
			printf(" %u",weight_sets[i]);
		printf("\n");
	}
	return 0;
}