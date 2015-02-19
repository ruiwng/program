#include  <stdio.h>
#include  <algorithm>
#include  <vector>
#include  <functional>
using namespace std;

int main()
{
	int m,n;
	int case_num=0;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m==0&&n==0)
			break;

		int upper=m*n;
		vector<int> tag_info(upper+1,0);
		vector<int> my_cards;
		for(int i=0;i<n;++i)
		{
			int temp;
			scanf("%d",&temp);
			tag_info[temp]=1;
			my_cards.push_back(temp);
		}
		sort(my_cards.begin(),my_cards.end(),greater<int>());
		int win_num=0;
		for(int i=0;i<n;++i)
		{
			int j=my_cards[i]+1;
			for(;j<=upper;++j)
			{
				if(tag_info[j]==0)
				{
					tag_info[j]=1;
					break;
				}
			}
			if(j>upper)
              ++win_num;
		}
		printf("Case %d: %d\n",++case_num,win_num);
	}
	return 0;
}