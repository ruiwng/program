/*使用红黑树，map set*/
/*#include  <stdio.h>
#include  <vector>
#include  <algorithm>
#include  <map>
#include  <set>
using namespace std;

typedef struct
{
	unsigned int refer1;
	unsigned int refer2;
}pair_refer;


int main()
{
	map<unsigned int,vector<unsigned int> > sets_array;
	unsigned int number;
	while(scanf("%u",&number)!=EOF)
	{
		vector<set<unsigned int> >  array(number);
		for(unsigned int i=0;i<number;i++)
		{
			unsigned int number_temp;
			scanf("%u",&number_temp);
			for(unsigned int j=0;j<number_temp;j++)
			{
				unsigned int num;
				scanf("%u",&num);
				array[i].insert(num);
				sets_array[num].push_back(i+1);
			}
		}
		vector<pair_refer> refer_array;
		unsigned int refer_num;
		scanf("%u",&refer_num);
		for(unsigned int i=0;i<refer_num;i++)
		{
			pair_refer refer_temp;
			scanf("%u %u",&refer_temp.refer1,&refer_temp.refer2);
			refer_array.push_back(refer_temp);
		}
		for(unsigned int i=0;i<refer_array.size();i++)
		{
		    unsigned int refer1_temp=refer_array[i].refer1,
				refer2_temp=refer_array[i].refer2;
			unsigned int sum_size=array[refer1_temp-1].size()+array[refer2_temp-1].size();
			unsigned int same_element=0;
			if(array[refer1_temp-1].size()<=array[refer2_temp-1].size())
			{
				for(set<unsigned int>::const_iterator iter=array[refer1_temp-1].begin();iter!=array[refer1_temp-1].end();++iter)
				{
					vector<unsigned int>& sets_temp=sets_array[*iter];
					if(find(sets_temp.begin(),sets_temp.end(),refer2_temp)!=sets_temp.end())
					{
						sum_size--;
						same_element++;
					}
				}
				printf("%.1f%%\n",static_cast<float>(same_element)/sum_size*100);
			}
			else 
			{
				for(set<unsigned int>::const_iterator iter=array[refer2_temp-1].begin();iter!=array[refer2_temp-1].end();++iter)
				{
					vector<unsigned int>& sets_temp=sets_array[*iter];
					if(find(sets_temp.begin(),sets_temp.end(),refer1_temp)!=sets_temp.end())
					{
						sum_size--;
						same_element++;
					}
				}
				printf("%.1f%%\n",static_cast<float>(same_element)/sum_size*100);
			}
		}
	}
}
*/

/*使用哈希表 unordered_map unordered_set*/

#include  <stdio.h>
#include  <vector>
#include  <algorithm>
#include  <unordered_map>
#include  <unordered_set>
using namespace std;

typedef struct
{
	unsigned int refer1;
	unsigned int refer2;
}pair_refer;


int main()
{
	unordered_map<unsigned int,vector<unsigned int> > sets_array;
	unsigned int number;
	while(scanf("%u",&number)!=EOF)
	{
		vector<unordered_set<unsigned int> >  array(number);
		for(unsigned int i=0;i<number;i++)
		{
			unsigned int number_temp;
			scanf("%u",&number_temp);
			for(unsigned int j=0;j<number_temp;j++)
			{
				unsigned int num;
				scanf("%u",&num);
				array[i].insert(num);
				sets_array[num].push_back(i+1);
			}
		}
		vector<pair_refer> refer_array;
		unsigned int refer_num;
		scanf("%u",&refer_num);
		for(unsigned int i=0;i<refer_num;i++)
		{
			pair_refer refer_temp;
			scanf("%u %u",&refer_temp.refer1,&refer_temp.refer2);
			refer_array.push_back(refer_temp);
		}
		for(unsigned int i=0;i<refer_array.size();i++)
		{
		    unsigned int refer1_temp=refer_array[i].refer1,
				refer2_temp=refer_array[i].refer2;
			unsigned int sum_size=array[refer1_temp-1].size()+array[refer2_temp-1].size();
			unsigned int same_element=0;
			if(array[refer1_temp-1].size()<=array[refer2_temp-1].size())
			{
				for(unordered_set<unsigned int>::const_iterator iter=array[refer1_temp-1].begin();iter!=array[refer1_temp-1].end();++iter)
				{
					vector<unsigned int>& sets_temp=sets_array[*iter];
					if(find(sets_temp.begin(),sets_temp.end(),refer2_temp)!=sets_temp.end())
					{
						sum_size--;
						same_element++;
					}
				}
				printf("%.1f%%\n",static_cast<float>(same_element)/sum_size*100);
			}
			else 
			{
				for(unordered_set<unsigned int>::const_iterator iter=array[refer2_temp-1].begin();iter!=array[refer2_temp-1].end();++iter)
				{
					vector<unsigned int>& sets_temp=sets_array[*iter];
					if(find(sets_temp.begin(),sets_temp.end(),refer1_temp)!=sets_temp.end())
					{
						sum_size--;
						same_element++;
					}
				}
				printf("%.1f%%\n",static_cast<float>(same_element)/sum_size*100);
			}
		}
	}
}