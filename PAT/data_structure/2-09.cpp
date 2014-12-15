#include  <stdio.h>
#include  <vector>
using namespace std;

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		vector<unsigned int> num_array(num);
		for(unsigned int i=0;i<num;++i)
		  scanf("%u",&num_array[i]);

		vector<unsigned int> case_array;
		case_array.push_back(100);

		for(unsigned int i=0;i<num;++i)
		{
			unsigned int case_size=case_array.size();
			bool find=false;
			for(unsigned int j=0;j<case_size;++j)
			{
				if(num_array[i]<=case_array[j])
				{
					find=true;
					case_array[j]-=num_array[i];
					printf("%u %u\n",num_array[i],j+1);
					break;
				}
			}
			if(!find)
			{
				case_array.push_back(100-num_array[i]);
				printf("%u %u\n",num_array[i],case_size+1);
			}
		}
		printf("%u\n",case_array.size());
	}
	return 0;
}