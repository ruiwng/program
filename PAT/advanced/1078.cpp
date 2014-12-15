#include  <stdio.h>
#include  <vector>
#include  <cmath>
using namespace std;

bool is_primer(unsigned int num)
{
	unsigned int num_temp=pow(num,0.5);
	unsigned int i;
	if(num==1)
	    return false;
	for(i=2;i<=num_temp;++i)
	{
		if(num%i==0)
			break;
	}
	if(i>num_temp)
		return true;
	else
		return false;
}

int main()
{
	unsigned int table_size,number;
	while(scanf("%u %u",&table_size,&number)!=EOF)
	{
		while(!is_primer(table_size))
			++table_size;
		vector<char> hash_array(table_size);
		for(unsigned int i=0;i<hash_array.size();++i)
			hash_array[i]='0';
		vector<unsigned int> number_array(number); 
		for(unsigned int i=0;i<number;++i)
			scanf("%u",&number_array[i]);

		bool first_key=true;
		for(unsigned int i=0;i<number;++i)
		{
			unsigned int key_temp=number_array[i];
			unsigned int j;
			for(j=0;j<table_size;++j)
			{
				unsigned int hash_temp=(key_temp+j*j)%table_size;
				if(hash_array[hash_temp]=='0')
				{
					hash_array[hash_temp]='1';
					if(first_key)
					{
						printf("%u",hash_temp);
						first_key=false;
					}
					else
						printf(" %u",hash_temp);
					break;
				}
			}
			if(j>=table_size)
			{
				if(first_key)
					{
						printf("-");
						first_key=false;
					}
				else
					printf(" -");
			}
		}
		printf("\n");
	}
	return 0;
}


