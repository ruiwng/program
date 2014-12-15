#include  <stdio.h>

struct record
{
	char name[15];
	char birthday[15];
	char gender[5];
	char phone[20];
	char mobile[20];
};

struct record record_array[10];

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		for(unsigned int i=0;i<num;++i)
			scanf("%s %s %s %s %s",record_array[i].name,record_array[i].birthday,
				record_array[i].gender,record_array[i].phone,record_array[i].mobile);
		unsigned int query;
		scanf("%u",&query);
		for(unsigned int i=0;i<query;++i)
		{
			int temp;
			scanf("%d",&temp);
			if(temp<0||temp>num-1)
				printf("Not Found\n");
			else
				printf("%s %s %s %s %s\n",record_array[temp].name,record_array[temp].phone,
				record_array[temp].mobile,record_array[temp].gender,record_array[temp].birthday);
		}
	}
	return 0;
}