#include  <string>
#include  <vector>
#include  <stdio.h>
#include  <algorithm>

using namespace std;

bool subarray(const string& s1,const string& s2)
{
	for(unsigned int i=0;i<s1.length();i++)
	{
		if(s1[i]!=s2[i])
			return false;
	}
	return true;
}

void exchange_str(vector<string>& str_a,unsigned int pos1,unsigned int pos2)
{
	for(unsigned int i=pos1;i<pos2;i++)
	{
		for(unsigned int j=i;j<pos2;j++)
		{
			string s1=str_a[j]+str_a[j+1];
			string s2=str_a[j+1]+str_a[j];
			if(s2<s1)
				str_a[j].swap(str_a[j+1]);
		}
	}
}
int main()
{
	unsigned int number_sum;
	while(scanf("%d",&number_sum)!=EOF)
	{
		vector<string> str_array;
		for(unsigned int i=0;i<number_sum;i++)
		{
			char str[10];
			scanf("%s",str);
			str_array.push_back(str);
		}
		sort(str_array.begin(),str_array.end());		
		for(unsigned int i=0;i<number_sum-1;i++)
		{
			if(!subarray(str_array[i],str_array[i+1]))
				continue;
			else
			{
				unsigned int current_pos=i;
				for(i=i+1;i<number_sum-1;i++)
				{
					if(!(subarray(str_array[i],str_array[i+1])))
						break;
				}
				exchange_str(str_array,current_pos,i);
			}
		}
		string sum;
		for(unsigned int i=0;i<str_array.size();i++)
			sum+=str_array[i];
		sum.erase(0,sum.find_first_not_of('0'));
		if(!sum.empty())
		   printf("%s\n",sum.c_str());
		else
			printf("0\n");
	}
	return 0;
}