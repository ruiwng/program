
#include  <stdio.h>
#include  <string>
using namespace std;

int main()
{
	char num1;
    unsigned int num2;
	char temp_array[30];
	while(fgets(temp_array,30,stdin)!=NULL)
	{
		sscanf(temp_array,"%c %u",&num1,&num2);
		if(num2==0)
			printf("0\n");
		else
		{
		    string sum(num2+1,num1);
			unsigned int temp=(num2+1)*(num1-'0');
			char str[10];
			sprintf(str,"%u",temp);
			string str_temp(str);
			size_t len=sum.length(),len_temp=str_temp.length();
			unsigned int borrow=0;
			size_t i;
			for(i=1;i<=len_temp;++i)
			{
				int sum_temp=sum[len-i]-str_temp[len_temp-i]-borrow;
				if(sum_temp<0)
				{
					sum_temp+=10;
					borrow=1;
				}
				else
					borrow=0;
				sum[len-i]=sum_temp+'0';
			}
			while(borrow!=0)
			{
				int sum_temp=sum[len-i]-'0'-borrow;
				if(sum_temp<0)
				{
					sum_temp+=10;
					borrow=1;
				}
				else
					borrow=0;
				sum[len-i]=sum_temp+'0';
				++i;
			}
			sum.erase(0,sum.find_first_not_of('0'));
			len=sum.length();
			borrow=0;
		    for(size_t i=0;i<len;++i)
		    {
				unsigned int sum_temp=sum[i]-'0'+borrow*10;
			    sum[i]=sum_temp/9+'0';
				borrow=sum_temp%9;
		    }
			sum.erase(0,sum.find_first_not_of('0'));			
		    printf("%s\n",sum.c_str());
		}
	}
	return 0;
}