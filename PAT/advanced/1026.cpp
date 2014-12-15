#include  <stdio.h>
#include  <vector>
#include  <algorithm>

using namespace std;

struct time_s
{
	int HH;
	int MM;
	int SS;
	time_s(int h=8,int m=0,int s=0):HH(h),MM(m),SS(s){}

	bool operator<(const time_s& t) const
	{
		if(this->HH!=t.HH)
			return this->HH<t.HH;
		if(this->MM!=t.MM)
			return this->MM<t.MM;
		return this->SS<t.SS;
	}
	bool operator==(const time_s& t) const
	{
		return this->HH==t.HH&&this->MM==t.MM&&this->SS==t.SS;
	}

	bool operator<=(const time_s& t) const
	{
		return *this<t||*this==t;
	}

	time_s& operator+=(int mm)
	{
		this->MM+=mm;
		if(this->MM>=60)
		{
			this->MM-=60;
			this->HH++;
		}
		return *this;
	}
};

time_s operator+(const time_s& t,int mm)
{
	time_s temp=t;
	temp.MM+=mm;
	if(temp.MM>=60)
	{
		temp.MM-=60;
		temp.HH++;
	}
	return temp;
}

void print_time(const time_s& temp)
{
	printf("%02d:%02d:%02d",temp.HH,temp.MM,temp.SS);
}
int operator-(const time_s& lhs,const time_s& rhs)
{
	time_s temp=lhs;
	if(temp.SS<rhs.SS)
	{
		temp.SS+=60;
		temp.MM--;
	}
	temp.SS-=rhs.SS;
	if(temp.MM<rhs.MM)
	{
		temp.MM+=60;
		temp.HH--;
	}
	temp.MM-=rhs.MM;
	temp.HH-=rhs.HH;
	int t=temp.HH*60+temp.MM;
	if(temp.SS>=30)
		++t;
	return t;
}

struct player
{
	time_s arrive_time;
	time_s serving_time;
	int play_time;
	int vip_tag;
	player():arrive_time(),serving_time(),play_time(0),vip_tag(0){}
	bool operator<(const player& rhs) const
	{
		return this->arrive_time<rhs.arrive_time;
	}
};


struct table
{
	time_s current_time;
	int vip_tag;
	int number_player;
	table():current_time(),vip_tag(0),number_player(0){}
	bool operator<(const table& rhs) const
	{
		return this->current_time<rhs.current_time;
	}
};

bool vip_func(const player& temp)
{
	return temp.vip_tag==1;
}

int main()
{
	int total_players;
	while(scanf("%d",&total_players)!=EOF)
	{
		vector<player> player_array(total_players);
		for(int i=0;i<total_players;++i)
			scanf("%02d:%02d:%02d %d %d",&player_array[i].arrive_time.HH,
			&player_array[i].arrive_time.MM,&player_array[i].arrive_time.SS,
			&player_array[i].play_time,&player_array[i].vip_tag);

		int table_num,vip_table_num;
		scanf("%d %d",&table_num,&vip_table_num);
		vector<table> table_array(table_num);
		for(int i=0;i<vip_table_num;++i)
		{
			int vip_temp;
			scanf("%d",&vip_temp);
			table_array[vip_temp-1].vip_tag=1;
		}	
		sort(player_array.begin(),player_array.end());

		time_s close_time(21,0,0);

		while(true)
		{
			if(player_array.empty()||close_time<=player_array.begin()->arrive_time)
				break;
			vector<table>::iterator table_current=min_element(table_array.begin(),table_array.end());
			
			if(close_time<=table_current->current_time)
				break;

			bool choose=false;
			vector<player>::iterator player_current;
			if(table_current->vip_tag==1)
			{
				player_current=find_if(player_array.begin(),player_array.end(),vip_func);
				if(player_current!=player_array.end()&&player_current->arrive_time<=table_current->current_time)
					choose=true;
			}
			if(!choose)
		       player_current=player_array.begin();	
			bool selected=false;
			if(!choose&&player_current->vip_tag==1)
			{
				for(vector<table>::iterator iter=table_array.begin();iter!=table_array.end();++iter)
				{
					if(iter->vip_tag==1&&iter->current_time<=player_current->arrive_time)
					{
						table_current=iter;
						selected=true;
						break;
					}
				}
			}
			if(!selected&&!choose&&table_current->current_time<=player_current->arrive_time)
			{
				for(vector<table>::iterator iter=table_array.begin();iter!=table_array.end();++iter)
				{
					if(iter->current_time<=player_current->arrive_time)
					{
						table_current=iter;
						break;
					}
				}
			}
			player_current->serving_time=max(player_current->arrive_time,table_current->current_time);
			if(player_current->serving_time<close_time)
			{
			   table_current->current_time=player_current->serving_time+min(120,player_current->play_time);
			   table_current->number_player++;
			   print_time(player_current->arrive_time);
			   printf(" ");
			   print_time(player_current->serving_time);
			   printf(" %d\n",player_current->serving_time-player_current->arrive_time);		   
			}		
			player_array.erase(player_current);
		}
	    printf("%d",table_array[0].number_player);
		for(int i=1;i<table_num;++i)
		 printf(" %d",table_array[i].number_player);
		printf("\n");
	}
	return 0;
}