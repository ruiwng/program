#include  <stdio.h>
#include  <string.h>

int main()
{
	char str[5];
	int eslapse;
	while(scanf("%s %d",str,&eslapse)!=EOF)
	{
		int str_len=strlen(str);
		int minute,hour;
		sscanf(str+str_len-2,"%u",&minute);
		str[str_len-2]='\0';
		sscanf(str,"%u",&hour);
		minute+=eslapse;
		while(minute<0)
		{
			minute+=60;
			hour--;
		}
		hour+=minute/60;
		minute%=60;
		printf("%u%02u\n",hour,minute);
	}
	return 0;
}