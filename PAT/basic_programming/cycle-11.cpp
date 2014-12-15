#include  <stdio.h>
#include  <math.h>
#include  <string.h>
#include  <vector>
using namespace std;
int main()
{
	int num;
	while(scanf("%d",&num)!=EOF)
	{
		unsigned int temp1=pow(static_cast<long double>(10),num-1);
		unsigned int temp2=pow(static_cast<long double>(10),num);

		vector<unsigned int> array(10);
		for(unsigned int i=0;i<10;++i)
			array[i]=pow(static_cast<long double>(i),num);

		for(unsigned int i=temp1;i<temp2;++i)
		{
			char str[12];
			sprintf(str,"%u",i);
			unsigned int sum=0;
			for(int j=0;j<num;++j)
				sum+=array[str[j]-'0'];
			if(sum==i)
				printf("%u\n",i);
		}
	}
}