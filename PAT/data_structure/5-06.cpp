#include  <stdio.h>
#include  <unordered_map>
#include  <string>
using namespace std;


int main()
{
	unsigned int number_record,low_threshold;
	while(scanf("%u %u",&number_record,&low_threshold)!=EOF)
	{
		unordered_map<string,unsigned int> distance_info;
		for(unsigned int i=0;i<number_record;++i)
		{
			char number[20];
			unsigned int distance_temp;
			scanf("%s %u",&number,&distance_temp);
			distance_info[number]+=max(distance_temp,low_threshold);
		}

		unsigned int query_number;
		scanf("%u",&query_number);
		for(unsigned int i=0;i<query_number;++i)
		{
			char number[20];
			scanf("%s",number);
			unordered_map<string,unsigned int>::iterator iter=distance_info.find(number);
			if(iter!=distance_info.end())
				printf("%u\n",iter->second);
			else
				printf("No Info\n");
		}
	}
	return 0;
}