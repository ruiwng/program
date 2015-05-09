#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;

struct score_info
{
	vector<int> score;
	int index;
	int sum_score;
	int solved;
	bool flag;
	score_info(int n):score(n,-1),index(0),sum_score(0),solved(0),flag(false){}
	bool operator<(const score_info &s) const
	{
		if(this->sum_score!=s.sum_score)
			return this->sum_score>s.sum_score;
		if(this->solved!=s.solved)
		    return this->solved>s.solved;
		return this->index<s.index;
	}
};

struct predicate
{
	bool operator()(const score_info& s) const
	{
		return s.flag;
	}
};

int main()
{
	int n,k,m;
	while(scanf("%d%d%d",&n,&k,&m)!=EOF)
	{
		vector<score_info> score_array(n+1,score_info(k));
		for(int i=0;i<=n;++i)
			score_array[i].index=i;
		vector<int> full_mark(k);
		for(int i=0;i<k;++i)
			scanf("%d",&full_mark[i]);
		for(int i=0;i<m;++i)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(score_array[a].score[b-1]==-1)
			    score_array[a].score[b-1]=0;
			if(c>=score_array[a].score[b-1])
			{
				if(c>score_array[a].score[b-1]&&c==full_mark[b-1])
					++score_array[a].solved;
				score_array[a].flag=true;
				score_array[a].sum_score+=c-score_array[a].score[b-1];
				score_array[a].score[b-1]=c;
			}
		}
		vector<score_info>::iterator iter=partition(score_array.begin(),score_array.end(),predicate());
		sort(score_array.begin(),iter);
		int len=iter-score_array.begin();
		int rank=0;
		for(int i=0;i<len;++i)
		{
			if(i==0||score_array[i].sum_score<score_array[i-1].sum_score)
				rank=i+1;
			printf("%d %05d %d",rank,score_array[i].index,score_array[i].sum_score);
			for(int j=0;j<k;++j)
			{
				if(score_array[i].score[j]==-1)
					printf(" -");
				else
					printf(" %d",score_array[i].score[j]);
			}
			printf("\n");
		}
	}
	return 0;
}