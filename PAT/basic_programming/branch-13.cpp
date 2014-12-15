#include  <stdio.h>
#include  <vector>
using namespace std;
int main()
{
	unsigned int year,month,day;
	while(scanf("%u/%u/%u",&year,&month,&day)!=EOF)
	{
		vector<unsigned int> month_array(13);
		month_array[1]=month_array[3]=month_array[5]=month_array[7]
		=month_array[8]=month_array[10]=month_array[12]=31;
		month_array[4]=month_array[6]=month_array[9]=month_array[11]=30;
		if((year%4==0&&year%100!=0)||year%400==0)
		  month_array[2]=29;
		else
			month_array[2]=28;
		unsigned int day_count=0;
		for(unsigned int i=1;i<month;++i)
		  day_count+=month_array[i];
		day_count+=day;
		printf("%u\n",day_count);
	}
	return 0;
}