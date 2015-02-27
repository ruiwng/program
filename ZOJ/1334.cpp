#include  <stdio.h>

int main()
{
	char str[20];
	int base_1,base_2;
	while(scanf("%s%d%d",str,&base_1,&base_2)!=EOF)
	{
		long long num=0;
		char *p=str;
		while(*p!='\0')
		{
			num=num*base_1+((*p>='0'&&*p<='9')?(*p-'0'):(*p-'A'+10));
			++p;
		}
		p=str;
		while(num!=0)
		{
			int remainder=num%base_2;
			*p++=remainder<10?('0'+remainder):('A'+remainder-10);
			num/=base_2;
		}
		*p='\0';
		if(p-str>7)
			printf("%7s\n","ERROR");
		else
		{
			--p;
			printf("%*c",6-(p-str),*(p--));
			while(p>=str)
				printf("%c",*p--);
			printf("\n");
		}
	}
	return 0;
}