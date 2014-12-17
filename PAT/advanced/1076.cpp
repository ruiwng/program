#include  <stdio.h>
#include  <vector>
#include  <queue>
using namespace std;

struct user
{
	bool known;
	vector<unsigned int> follow_array;
	unsigned int level;
	user():known(false),follow_array(vector<unsigned int>()),level(0){}
};
int main()
{
	unsigned int number_user,levels;
	while(scanf("%u %u",&number_user,&levels)!=EOF)
	{
		vector<user> user_array(number_user+1);
		for(unsigned int i=1;i<=number_user;++i)
		{
			unsigned int follow_numbers;
			scanf("%u",&follow_numbers);
			for(unsigned int j=0;j<follow_numbers;++j)
			{
				unsigned int temp;
				scanf("%u",&temp);
				user_array[temp].follow_array.push_back(i);
			}
		}

		unsigned int query_number;
		scanf("%u",&query_number);
		vector<unsigned int> query_array(query_number);
		for(unsigned int i=0;i<query_number;++i)
		 scanf("%u",&query_array[i]);

		for(unsigned int i=0;i<query_number;++i)
		{
			unsigned int follow_sum=0;
			queue<unsigned int> queue_array;
			for(unsigned int j=1;j<=number_user;++j)
			  user_array[j].known=false;
			user_array[query_array[i]].level=0;
			queue_array.push(query_array[i]);
			user_array[query_array[i]].known=true;
			while(!queue_array.empty())
			{
				user& user_temp=user_array[queue_array.front()];
				queue_array.pop();
				unsigned int current_level=user_temp.level+1;
				if(current_level>levels)
					break;
				vector<unsigned int>& follow_temp=user_temp.follow_array;
				for(unsigned int j=0;j<follow_temp.size();++j)
				{
					if(user_array[follow_temp[j]].known)
						continue;
					user_array[follow_temp[j]].level=current_level;
					user_array[follow_temp[j]].known=true;
					queue_array.push(follow_temp[j]);
					   follow_sum++;
				}
			}
			printf("%u\n",follow_sum);
		}
	}
	return 0;
}