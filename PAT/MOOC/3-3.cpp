#include  <stdio.h>

int main()
{
     unsigned int hour,minute;
	 while(scanf("%u:%u",&hour,&minute)!=EOF)
	 {
		 if(hour<12)
			 printf("%u:%u AM\n",hour,minute);
		 else if(hour==12)
			 printf("%u:%u PM\n",hour,minute);
		 else
			 printf("%u:%u PM\n",hour-12,minute);
	 }
	 return 0;
}