#include  <stdio.h>
#include  <set>
using namespace std;

struct forward_info
{
	int start_time;//time started
	int duration;//time  lasted
	int target;
	bool operator<(const forward_info& f) const
	{
		return this->start_time<f.start_time;
	}
	forward_info(int s=0,int d=0,int t=0):
		start_time(s),duration(d),target(t){}
};

int main()
{
	int system_number;
	printf("CALL FORWARDING OUTPUT\n");
	while(scanf("%d",&system_number)!=EOF)
	{
		for(int i=0;i<system_number;++i)
		{
			printf("SYSTEM %d\n",i+1);
			set<forward_info> forward_array[10000];//a hash table using the source as the key to represent all forward information.
			while(true)
			{
				int source;
			    forward_info forward_temp;
			    scanf("%d",&source);
			    if(source==0)
				   break;
			    scanf("%d%d%d",&forward_temp.start_time,
				&forward_temp.duration,&forward_temp.target);
				forward_array[source].insert(forward_temp);//insert the forward information.
			}
			while(true)
			{
				int time_query;
				int extension;
				scanf("%d",&time_query);
				if(time_query==9000)
					break;
				scanf("%d",&extension);
				int target=extension;
				set<int> traversed;//extension traversed
				while(true)
				{
					if(traversed.find(target)==traversed.end())
						traversed.insert(target);
					else
					{
						target=9999;
						break;
					}
					const set<forward_info>& forward_ref=forward_array[target];
				    set<forward_info>::const_iterator iter=forward_ref.upper_bound(forward_info(time_query));
				    if(iter==forward_ref.begin())
						break;
					--iter;
					if(iter->start_time+iter->duration<time_query)
						break;
					else
						target=iter->target;
				}
				printf("AT %04d CALL TO %04d RINGS %04d\n",time_query,extension,target);
			}
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
