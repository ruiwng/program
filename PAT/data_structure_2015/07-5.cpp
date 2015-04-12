#include  <stdio.h>
#include  <string.h>
#include  <vector>
using namespace std;

const int max_distance=0x70000000;

struct road_info
{
	int distance;
	int price;
};
road_info info_array[500][500];

struct pos_info
{
	int min_dist;
	int price;
	bool flag;
	pos_info():min_dist(max_distance),price(0),flag(false){}
};

int main()
{
	int n,m,s,d;
	while(scanf("%d%d%d%d",&n,&m,&s,&d)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				info_array[i][j].distance=info_array[j][i].distance=max_distance;
				info_array[i][j].price=info_array[j][i].price=0;
			}
		}
		for(int i=0;i<m;++i)
		{
			int start,end,dis,p;
			scanf("%d%d%d%d",&start,&end,&dis,&p);
			info_array[start][end].distance=info_array[end][start].distance=dis;
			info_array[start][end].price=info_array[end][start].price=p;
		}
		vector<pos_info> pos_array(n);
		pos_array[s].min_dist=0;
		while(true)
		{
			int min_index;
			int current_dist=max_distance;
			for(int i=0;i<n;++i)
			{
				if(!pos_array[i].flag&&pos_array[i].min_dist<current_dist)
				{
					min_index=i;
					current_dist=pos_array[i].min_dist;
				}
			}
			if(min_index==d)
			{
				printf("%d %d\n",pos_array[d].min_dist,pos_array[d].price);
				break;
			}
			pos_array[min_index].flag=true;
			for(int i=0;i<n;++i)
			{
				if(pos_array[i].flag)
					continue;
				if(pos_array[min_index].min_dist+info_array[min_index][i].distance<pos_array[i].min_dist||
					(pos_array[min_index].min_dist+info_array[min_index][i].distance==pos_array[i].min_dist&&
					pos_array[min_index].price+info_array[min_index][i].price<pos_array[i].price))
				{
					pos_array[i].min_dist=pos_array[min_index].min_dist+info_array[min_index][i].distance;
					pos_array[i].price=pos_array[min_index].price+info_array[min_index][i].price;
				}
			}
		}
	}
	return 0;
}