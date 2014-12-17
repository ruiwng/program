#include  <stdio.h>
#include  <string.h>

int main()
{
	char str[30];
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		unsigned int num_array[10];
		for(unsigned int i=0;i<10;++i)
			num_array[i]=0;
		for(unsigned int i=0;i<num;++i)
		{
			scanf("%s",str);
			unsigned int length=strlen(str);
			for(unsigned int i=0;i<length;++i)
				num_array[str[i]-'0']++;
		}
		unsigned int apperance=0;
		unsigned int index=0;
		unsigned int satisfy_array[10];
		for(unsigned int i=0;i<10;++i)
		{
			if(num_array[i]==apperance)
				satisfy_array[index++]=i;
			else if(num_array[i]>apperance)
			{
				apperance=num_array[i];
				satisfy_array[0]=i;
				index=1;
			}
		}
		printf("%u:",apperance);
		for(unsigned int i=0;i<index;++i)
			printf(" %u",satisfy_array[i]);
		printf("\n");
	}
	return 0;
}