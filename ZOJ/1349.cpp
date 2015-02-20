#include  <stdio.h>
#include  <map>
using namespace std;

struct score
{
	score(int x1=0,int y1=0):x(x1),y(y1){}
	int x;
	int y;
	bool operator<(const score& s) const
	{
		if(this->x!=s.x)
			return this->x<s.x;
		return this->y<s.y;
	}
};

struct record
{
	int x,y;
	double p;
};

record probability[6]=
{
	{1,0,0.25},
	{1,-1,0.125},
	{0,0,0.375},
	{2,-1,0.0625},
	{0,1,0.125},
	{-1,2,0.0625},
};

int main()
{
	printf("Round   A wins    B wins    Tie\n");
	map<score,double> score_info;
	score_info.insert(make_pair(score(0,0),1.0));
	for(int i=1;i<=20;++i)
	{
		map<score,double> score_temp;
	    double A_win=0.0;
		double B_win=0.0;
		double tie=0.0;
		for(map<score,double>::iterator iter=score_info.begin();iter!=score_info.end();++iter)
		{
			for(int j=0;j<6;++j)
			{
				double probability_temp=iter->second*probability[j].p;
				score s(iter->first.x+probability[j].x,iter->first.y+probability[j].y);
				if(s.x>s.y)
					A_win+=probability_temp;
				else if(s.x<s.y)
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