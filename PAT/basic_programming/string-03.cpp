#include  <stdio.h>
#include  <iostream>
#include  <string>
#include  <vector>
#include  <algorithm>
using namespace std;

void print(const string& str)
{
	printf("%s\n",str.c_str());
}
int main()
{
	unsigned int num1,num2;
	while(scanf("%u %u",&num1,&num2)!=EOF)
	{
		vector<string> str_array(num1);
		for(unsigned int i=0;i<num1;++i)
			cin>>str_array[i];

		for(unsigned int i=1;i<=num2;++i)
		{
			for(unsigned int j=0;j<num1-i;++j)
				if(str_array[j]>str_array[j+1])
					str_array[j].swap(str_array[j+1]);
		}
		for_each(str_array.begin(),str_array.end(),print);
	}
	return 0;
}