#include  <stdio.h>
#include  <vector>
#include  <numeric>
#include  <math.h>
using namespace std;


int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		vector<int> number_array(num);
		for(unsigned int i=0;i<num;++i)
			scanf("%d",&number_array[i]);

		double sum=accumulate(number_array.begin(),number_array.end(),0);
		double average=sum/num;

		double temp=0;
		for(unsigned int i=0;i<num;++i)
			temp+=pow(number_array[i]-average,2);

		printf("%.5lf\n",sqrt(temp/num));
	}
	return 0;
}