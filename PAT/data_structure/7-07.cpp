#include  <stdio.h>
#include  <list>
using namespace std;

struct student
{
	unsigned long long number;
	unsigned int score;
	unsigned int position;
	unsigned int local_rank;
	student():number(0),score(0),position(0),local_rank(0){}
	bool operator<(const student& stu) const
	{
		if(this->score!=stu.score)
			return this->score>stu.score;
		else
			return this->number<stu.number;
	}
};


int main()
{
	unsigned int sum;
	while(scanf("%u",&sum)!=EOF)
	{
		list<student> global_info;
		for(unsigned int i=1;i<=sum;++i)
		{
			list<student> local_info;
			unsigned int local_sum;
			scanf("%u",&local_sum);
			for(unsigned int j=0;j<local_sum;++j)
			{
				student stu_temp;
				scanf("%llu %u",&stu_temp.number,&stu_temp.score);
				stu_temp.position=i;
				local_info.push_back(stu_temp);
			}
			local_info.sort();
			unsigned int local_rank=0;
			unsigned int number=0;
			for(list<student>::iterator iter=local_info.begin();iter!=local_info.end();++iter)
			{
				number++;
				if(iter==local_info.begin()||iter->score<prev(iter)->score)
					local_rank=number;
				iter->local_rank=local_rank;
			}
			global_info.merge(local_info);
		}
		printf("%u\n",global_info.size());
		unsigned int global_rank=0;
		unsigned int number=0;
		for(list<student>::iterator iter=global_info.begin();iter!=global_info.end();++iter)
		{
			number++;
			if(iter==global_info.begin()||iter->score<prev(iter)->score)
				global_rank=number;
			printf("%013llu %u %u %u\n",iter->number,global_rank,iter->position,iter->local_rank);
		}
	}
	return 0;
}

