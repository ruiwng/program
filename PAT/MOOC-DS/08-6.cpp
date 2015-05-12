#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;

struct person
{
	bool flag;
	int id;
	int total_score;
	int num_full;
	vector<int> score_arry;
	person(int n):flag(false),id(0),total_score(0),num_full(0),score_arry(n,-1){}
	bool operator<(const person& p) const
	{
		if(this->total_score!=p.total_score)
			return this->total_score>p.total_score;
		if(this->num_full!=p.num_full)
			return this->num_full>p.num_full;
		return this->id<p.id;
	}
};

struct predicate
{
	bool operator()(const person& p) const
	{
		return p.flag;
	}
};

int main()
{
	int n,k,m;
	while(scanf("%d%d%d",&n,&k,&m)!=EOF)
	{
		vector<int> mark_info(k);
		for(int i=0;i<k;++i)
			scanf("%d",&mark_info[i]);
		vector<person> person_array(n+1,person(k));
		for(int i=1;i<=n;++i)
			person_array[i].id=i;
		for(int i=0;i<m;++i)
		{
			int user_id,problem,score;
			scanf("%d%d%d",&user_id,&problem,&score);
			if(person_array[user_id].score_arry[problem-1]==-1)
				person_array[user_id].score_arry[problem-1]=0;
			if(score>=person_array[user_id].score_arry[problem-1])
			{
				if(score==mark_info[problem-1]&&score>person_array[user_id].score_arry[problem-1])
					++person_array[user_id].num_full;
				 person_array[user_id].flag=true;
				 person_array[user_id].total_score+=score-person_array[user_id].score_arry[problem-1];
				 person_array[user_id].score_arry[problem-1]=score;
			}
		}
		vector<person>::iterator iter=partition(person_array.begin(),person_array.end(),predicate());
		int len=iter-person_array.begin();
		sort(person_array.begin(),iter);
		int rank=0;
		for(int i=0;i<len;++i)
		{
			if(i==0||person_array[i].total_score<person_array[i-1].total_score)
				rank=i+1;
			printf("%d %05d %d",rank,person_array[i].id,person_array[i].total_score);
			for(int j=0;j<k;++j)
			{
				if(person_array[i].score_arry[j]!=-1)
					printf(" %d",person_array[i].score_arry[j]);
				else
					printf(" -");
			}
			printf("\n");
		}
	}
	return 0;
}