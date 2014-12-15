#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;
int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		vector<int> num_array[2];
        num_array[0].resize(num);
		num_array[1].resize(num);
		for(unsigned int i=0;i<2;++i)
		  for(unsigned int j=0;j<num;++j)
		    scanf("%d",&num_array[i][j]);

		vector<int> all_array(num*2);
		merge(num_array[0].begin(),num_array[0].end(),num_array[1].begin(),
			num_array[1].end(),all_array.begin());

		vector<int>::iterator iter=all_array.begin()+(all_array.size()-1)/2;
		nth_element(all_array.begin(),iter,all_array.end());

		printf("%d\n",*iter);
	}
}