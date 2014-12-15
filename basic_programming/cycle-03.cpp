#include  <stdio.h>
#include  <vector>
using namespace std;

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		vector<unsigned int> num_array(4);
		for(unsigned i=0;i<4;++i)
			num_array[i]=num+i;
		char str[4];
		str[3]='\0';
		for(unsigned int i=0;i<4;++i)
		{
			str[0]=num_array[i]+'0';
			bool first_time=true;
			for(unsigned int j=0;j<4;++j)
			{
				if(j==i)
					continue;
				str[1]=num_array[j]+'0';
				for(unsigned int k=0;k<4;++k)
				{
					if(k==i||k==j)
						continue;
					str[2]=num_array[k]+'0';
					if(first_time)
					{
					   printf("%s",str);
					   first_time=false;
					}
					else
						printf(" %s",str);
				}
			}
			printf("\n");
		}
	}
	return 0;
}