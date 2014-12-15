#include  <stdio.h>
#include  <vector>
#include  <algorithm>

using namespace std;

int main()
{
	unsigned int num1,num2;
	while(scanf("%u",&num1)!=EOF)
	{
		vector<int> num_array1(num1);
		for(unsigned int i=0;i<num1;++i)
			scanf("%d",&num_array1[i]);
		scanf("%u",&num2);
		vector<int> num_array2(num2);
		for(unsigned int i=0;i<num2;++i)
			scanf("%d",&num_array2[i]);

		bool first_element=true;
		vector<int> result_array;
		for(unsigned int i=0;i<num1;++i)
		{
			vector<int>::iterator iter=find(num_array2.begin(),num_array2.end(),num_array1[i]);
			if(iter!=num_array2.end())
				continue;
			iter=find(result_array.begin(),result_array.end(),num_array1[i]);
			if(iter==result_array.end())
				result_array.push_back(num_array1[i]);
		}
		for(unsigned int i=0;i<num2;++i)
		{
			vector<int>::iterator iter=find(num_array1.begin(),num_array1.end(),num_array2[i]);
			if(iter!=num_array1.end())
				continue;
			iter=find(result_array.begin(),result_array.end(),num_array2[i]);
			if(iter==result_array.end())
				result_array.push_back(num_array2[i]);
		}

		if(!result_array.empty())
			printf("%d",result_array[0]);
		for(unsigned int i=1;i<result_array.size();++i)
		    printf(" %d",result_array[i]);
		printf("\n");
	}
}