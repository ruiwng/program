/*#include  <stdio.h>
#include  <vector>
#include  <math.h>
using namespace std;
int main()
{
	long int num;
	while(scanf("%ld",&num)!=EOF)
	{
		vector<char> array(num+1);
		long int range=sqrt(num);
		for(long int i=2;i<=range;++i)
		{
			if(array[i]!=0)
				continue;
			long int temp=i+i;
			while(temp<=num)
			{
				array[temp]=1;
				temp+=i;
			}
		}

		bool first_time=true;
		printf("%ld=",num);
		if(num==1)
			printf("1");
		else
		for(long int i=2;i<=num;++i)
		{
			if(array[i]!=0)
				continue;
			unsigned int count=0;
			while(num%i==0)
			{
				num/=i;
				count++;
			}
			if(count==0)
				continue;
			if(first_time)
			  first_time=false;
			else
				printf("*");
			printf("%ld",i);
			if(count>1)
				printf("^%u",count);
		}
		printf("\n");
	}
	return 0;
}
*/

#include  <stdio.h>
#include  <math.h>

bool is_primer(long int number)
{
     long int temp=sqrt(static_cast<double>(number));
	 unsigned int i;
	 for(i=2;i<=temp;++i)
	 {
		 if(number%i==0)
			 break;
	 }
	 if(i>temp)
		 return true;
	 else
		 return false;
}

int main()
{
	long int num;
	while(scanf("%ld",&num)!=EOF)
	{

		bool first_time=true;
		printf("%ld=",num);
		if(num==1)
			printf("1");
		else
		for(long int i=2;i<=num;++i)
		{
			if(num%i!=0&&!is_primer(i))
				continue;
			unsigned int count=0;
			while(num%i==0)
			{
				num/=i;
				count++;
			}
			if(count==0)
				continue;
			if(first_time)
			  first_time=false;
			else
				printf("*");
			printf("%ld",i);
			if(count>1)
				printf("^%u",count);
		}
		printf("\n");
	}
	return 0;
}