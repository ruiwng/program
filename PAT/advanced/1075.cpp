#include  <stdio.h>
#include  <vector>
#include  <algorithm>

using namespace std;

typedef struct
{
	unsigned int user_id;
	unsigned int problem_id;
	int partial_score;
}submit_info;

struct personal_info
{
	unsigned int user_id;
	int total_score;
	unsigned int perfect_solved;
	bool pass;
	vector<int> part_score;
	personal_info(unsigned int id=0,int score=0,unsigned int solved=0):user_id(id),total_score(score),
		perfect_solved(solved),pass(false),part_score(){}
};

struct personal_cmp
{
	bool operator()(const personal_info& info1,const personal_info& info2) const
	{
		if(info1.total_score!=info2.total_score)
			return info1.total_score>info2.total_score;
		if(info1.perfect_solved!=info2.perfect_solved)
			return info1.perfect_solved>info2.perfect_solved;
		return info1.user_id<info2.user_id;
	}
};
int main()
{
	unsigned int number_users,number_problems,number_submittions;
	while(scanf("%u %u %u",&number_users,&number_problems,&number_submittions)!=EOF)
	{
		vector<int> scores_array(number_problems+1);
		vector<personal_info> rank_array(number_users+1);
		for(unsigned int i=1;i<=number_problems;++i)
			scanf("%d",&scores_array[i]);
		submit_info info_temp;
		for(unsigned int i=0;i<number_submittions;++i)
		{
			scanf("%u %u %d",&info_temp.user_id,&info_temp.problem_id,&info_temp.partial_score);
			unsigned int id_temp=info_temp.user_id;
			if(rank_array[id_temp].part_score.empty())
			   rank_array[id_temp].part_score.resize(number_problems+1,-1);
			if(info_temp.partial_score==-1)
			{
				if(rank_array[id_temp].part_score[info_temp.problem_id]==-1)
				    rank_array[id_temp].part_score[info_temp.problem_id]=0;
				continue;
			}
			rank_array[id_temp].pass=true;
			rank_array[id_temp].user_id=id_temp;
			if(info_temp.partial_score>rank_array[id_temp].part_score[info_temp.problem_id])
			{
			   if(info_temp.partial_score==scores_array[info_temp.problem_id])
				  rank_array[id_temp].perfect_solved++;
			   if(rank_array[id_temp].part_score[info_temp.problem_id]==-1)
				  rank_array[id_temp].total_score+=info_temp.partial_score;
			   else
				  rank_array[id_temp].total_score+=info_temp.partial_score-rank_array[id_temp].part_score[info_temp.problem_id];
			   rank_array[id_temp].part_score[info_temp.problem_id]=info_temp.partial_score;
				
			}
		}
		sort(rank_array.begin()+1,rank_array.end(),personal_cmp());
		unsigned int rank_number;
		for(unsigned int i=1;i<rank_array.size();++i)
		{
			if(i==1||rank_array[i-1].total_score>rank_array[i].total_score)
				rank_number=i;
			if(!rank_array[i].pass)
				continue;
			printf("%u %05u %d",rank_number,rank_array[i].user_id,rank_array[i].total_score);
			vector<int>& problems_array(rank_array[i].part_score);
			for(unsigned int j=1;j<=number_problems;++j)
			{
				if(problems_array[j]==-1)
					printf(" -");
				else
					printf(" %d",problems_array[j]);
			}
			printf("\n");
		}
	}
	return 0;
}