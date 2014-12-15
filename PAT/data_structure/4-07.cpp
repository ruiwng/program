#include  <stdio.h>
#include  <queue>
#include  <functional>

using namespace std;
int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		priority_queue<unsigned int,vector<unsigned int>,greater<unsigned int> > num_array;
		for(unsigned int i=0;i<num;++i)
		{
			unsigned int num_temp;
			scanf("%u",&num_temp);
			num_array.push(num_temp);
		}
		unsigned int sum=0;
		while(!num_array.empty())
		{
			unsigned int number1=num_array.top();
			num_array.pop();
			if(num_array.empty())
				break;
			unsigned int number2=num_array.top();
			num_array.pop();
			unsigned int temp=number1+number2;
			sum+=temp;
			num_array.push(temp);
		}
		printf("%u\n",sum);
	}
	return 0;
}