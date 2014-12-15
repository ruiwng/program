#include  <stdio.h>
#include  <vector>
using namespace std;

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		vector<unsigned int> array_info(num);
		for(unsigned int i=0;i<num;++i)
			array_info[i]=i+1;
		unsigned int i=1,j=0;
		while(true)
		{
			++i;
			j=(j+1)%array_info.size();
			if(i%3==0)
			{
				array_info.erase(array_info.begin()+j);
				++i;
			}
			if(array_info.size()==1)
				break;
		}
		printf("%u\n",array_info[0]);
	}
	return 0;
}