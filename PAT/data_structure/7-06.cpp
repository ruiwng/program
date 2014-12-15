#include  <stdio.h>
#include  <vector>
#include  <algorithm>

using namespace std;

struct info
{
	vector<double> score_array;
	unsigned int people_sum;
	vector<int> rank;
	info():people_sum(0){score_array.resize(4),rank.resize(4);}
};

bool cmp_gold(const info* info1,const info* info2)
{
	return info1->score_array[0]>info2->score_array[0];
}

bool cmp_medal(const info* info1,const info* info2)
{
	return info1->score_array[1]>info2->score_array[1];
}

bool cmp_gold_average(const info* info1,const info* info2)
{
	return info1->score_array[2]>info2->score_array[2];;
}

bool cmp_medal_average(const info* info1,const info* info2)
{
	return info1->score_array[3]>info2->score_array[3];;
}

typedef bool (*cmp)(const info* info1,const info* info2);

cmp cmp_array[4]={cmp_gold,cmp_medal,cmp_gold_average,cmp_medal_average};

int main()
{
	unsigned int country_number,country_query;
	while(scanf("%u %u",&country_number,&country_query)!=EOF)
	{
		vector<info> info_array(country_number);
		vector<info*> pinfo_array(country_number);
		vector<unsigned int> query_array(country_query);
		for(unsigned int i=0;i<country_number;++i)
		{
			scanf("%lf %lf %u",&info_array[i].score_array[0],&info_array[i].score_array[1],
				&info_array[i].people_sum);
			info_array[i].score_array[2]=info_array[i].score_array[0]/info_array[i].people_sum;
			info_array[i].score_array[3]=info_array[i].score_array[1]/info_array[i].people_sum;
		    pinfo_array[i]=&info_array[i];
		}

		for(unsigned int i=0;i<country_query;++i)
		   scanf("%u",&query_array[i]);

		for(unsigned int i=0;i<4;i++)
		{
			sort(pinfo_array.begin(),pinfo_array.end(),cmp_array[i]);
			unsigned int rank_number=0;
			for(unsigned int j=0;j<country_number;++j)
			{
				if(j==0||pinfo_array[j-1]->score_array[i]>pinfo_array[j]->score_array[i])
					rank_number=j+1;
				pinfo_array[j]->rank[i]=rank_number;
			}
		}

		bool first_time=true;
		for(unsigned int i=0;i<country_query;++i)
		{
			vector<int>& rank_temp=info_array[query_array[i]].rank;
			vector<int>::iterator min_iter=min_element(rank_temp.begin(),rank_temp.end());
			if(first_time)
				first_time=false;
			else
				printf(" ");
			printf("%d:%u",*min_iter,min_iter-rank_temp.begin()+1);
		}
		printf("\n");
	}
	return 0;
}