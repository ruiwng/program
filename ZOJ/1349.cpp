#include  <stdio.h>
#include  <map>
using namespace std;

struct record
{
	int score;
	double p;
};

record probability[6]=
{
	{1,0.25},
	{2,0.125},
	{0,0.375},
	{3,0.0625},
	{-1,0.125},
	{-3,0.0625},
};

int main()
{
	printf("Round   A wins    B wins    Tie\n");
	map<int,double> score_info;
	score_info.insert(make_pair(0,1.0));
	for(int i=1;i<=20;++i)
	{
		map<int,double> score_temp;
	    double A_win=0.0;
		double B_win=0.0;
		double tie=0.0;
		for(map<int,double>::iterator iter=score_info.begin();iter!=score_info.end();++iter)
		{
			for(int j=0;j<6;++j)
			{
				double probability_temp=iter->second*probability[j].p;
				int s=iter->first+probability[j].score;
				if(s>0)
					A_win+=probability_temp;
				else if(s<0)
					B_win+=probability_temp;
				else
					tie+=probability_temp;
				score_temp[s]+=probability_temp;
			}
		}
		printf("%5d   %7.4lf%%  %7.4lf%%  %7.4lf%%\n",i,A_win*100,B_win*100,tie*100);
		score_info.swap(score_temp);
	}
	return 0;
}