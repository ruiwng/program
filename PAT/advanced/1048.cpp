#include  <stdio.h>
#include  <string.h>

int hash_table[1001];
int main()
{
	unsigned int total_number,pay_amount;
	while(scanf("%u %u",&total_number,&pay_amount)!=EOF)
	{
		memset(hash_table,'\0',sizeof(hash_table));

		for(unsigned int i=0;i<total_number;++i)
		{
			unsigned int temp;
			scanf("%u",&temp);
			hash_table[temp]++;
		}

		bool find=false;
		unsigned int half_number=pay_amount>>1;
		unsigned int i;
		for(i=1;i<=half_number;++i)
		{
			if(hash_table[i]>0&&hash_table[pay_amount-i]>0)
			{
				find=true;
				break;
			}
		}
		if(find&&i+i==pay_amount&&hash_table[i]<=1)
			find=false;
		if(find)
			printf("%u %u\n",i,pay_amount-i);
		else
			printf("No Solution\n");
	}
	return 0;
}
