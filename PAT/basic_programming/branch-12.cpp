#include  <stdio.h>

typedef struct
{
	unsigned int hour;
	unsigned int minute;
}time;
int main()
{
	time begin,end;
	while(scanf("%02u%2u %02u%02u",&begin.hour,&begin.minute,&end.hour,&end.minute)!=EOF)
	{
		time temp;
		if(end.minute>=begin.minute)
			temp.minute=end.minute-begin.minute;
		else
		{
			temp.minute=end.minute+60-begin.minute;
			end.hour--;
		}
		temp.hour=end.hour-begin.hour;
		printf("%02u:%02u\n",temp.hour,temp.minute);
		
	}
	return 0;
}