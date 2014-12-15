#include  <stdio.h>
#include  <vector>
using namespace std;

struct info
{
	char name[11];
	char birthday[15];
	char gender[2];
	char phone[20];
	char mobile[20];
};

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		vector<info> info_array(num);
		for(unsigned int i=0;i<num;++i)
		   scanf("%s %s %s %s %s",info_array[i].name,info_array[i].birthday,
		   info_array[i].gender,info_array[i].mobile,info_array[i].phone);

		unsigned int query_number;
		scanf("%u",&query_number);
		vector<unsigned int> query_array(query_number);
		for(unsigned int i=0;i<query_number;++i)
		  scanf("%u",&query_array[i]);

		for(unsigned int i=0;i<query_number;++i)
		{
			if(query_array[i]>=num)
				printf("Not Found\n");
			else
				printf("%s %s %s %s %s\n",info_array[query_array[i]].name,info_array[query_array[i]].mobile,
				info_array[query_array[i]].phone,info_array[query_array[i]].gender,
				info_array[query_array[i]].birthday);
		}
	}
	return 0;
}