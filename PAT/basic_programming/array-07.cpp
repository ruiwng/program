#include  <stdio.h>
#include  <vector>
#include  <string>
#include  <iostream>
using namespace std;

int array[10];
int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		vector<string> str_array(num);
		for(unsigned int i=0;i<num;++i)
			cin>>str_array[i];	
		for(unsigned int i=0;i<num;++i)
		{
			for(unsigned int j=0;j<str_array[i].size();++j)
				array[str_array[i][j]-'0']++;
		}
		int max_num=0;
		vector<int> max_array;
		for(unsigned int i=0;i<10;++i)
		{
			if(array[i]>max_num)
			{
				max_array.clear();
				max_array.push_back(i);
				max_num=array[i];
			}
			else if(array[i]==max_num)
				max_array.push_back(i);
			else
				continue;
		}
		printf("%d:",max_num);
		for(unsigned int i=0;i<max_array.size();++i)
			printf(" %d",max_array[i]);
		printf("\n");
	}
	return 0;
}