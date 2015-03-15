#include  <stdio.h>
#include  <string.h>
#include  <vector>
#include  <set>
#include  <map>
#include  <string>
#include  <algorithm>
using namespace std;

struct tim
{
	int HH;
	int MM;
	int SS;
	tim(int h=0,int m=0,int s=0):HH(h),MM(m),SS(s){}
	tim(const tim& t):HH(t.HH),MM(t.MM),SS(t.SS){}
	bool operator<(const tim& t) const
	{
		if(this->HH!=t.HH)
			return this->HH<t.HH;
		if(this->MM!=t.MM)
			return this->MM<t.MM;
		return this->SS<t.SS;
	}
};

int operator-(const tim& lhs,const tim& rhs)
{
	int n=0;
	tim temp(lhs);
	if(temp.SS<rhs.SS)
	{
		temp.SS+=60;
		temp.MM-=1;
	}
	n+=lhs.SS-rhs.SS;
	if(temp.MM<rhs.MM)
	{
		temp.MM+=60;
		temp.HH-=1;
	}
	n+=(temp.MM-rhs.MM)*60;
	n+=(temp.HH-rhs.HH)*3600;
	return n;
}

struct record
{
	char name[10];
	tim t;
	bool flag;
	bool operator<(const record& r) const
	{
		return this->t<r.t;
	}
};

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		vector<record> record_array;
		for(int i=0;i<n;++i)
		{
			record temp;
			char s[5];
            scanf("%s %d:%d:%d %s",temp.name,&temp.t.HH,&temp.t.MM,&temp.t.SS,s);
			if(strcmp(s,"in")==0)
				temp.flag=true;
			else
				temp.flag=false;
			record_array.push_back(temp);
		}
		map<string,tim> record_map;
		vector<string> longest_array;
		map<tim,int> park_info;
		int longest_length=0;
        for(int j=0;j<n;++j)
		{
			if(record_array[j].flag)
				record_map.insert(make_pair(record_array[j].name,record_array[j].t));
			else
			{
				map<string,tim>::iterator iter=record_map.find(record_array[j].name);
				if(iter!=record_map.end())
				{
					  ++park_info[iter->second];
					  --park_info[record_array[j].t];
					  int t=record_array[j].t-iter->t;
					  if(t>longest_length)
					  {
						  longest_length=t;
						  longest_array.clear();
						  longest_array.push_back(record_array[i].name);
					  }
					  else if(t==longest_length)
						  longest_array.push_back(record_array[i].name);
					  record_map.erase(iter);
				}
			}
		}
		int x=0;
		for(map<tim,int>::iterator it=park_info.begin();it!=park_info.end();++it)
		{
			it->second+=x;
			x=it->second;
		}
		for(int m=0;m<k;++m)
		{
			tim temp;
			scanf("%d:%d:%d",&temp.HH,&temp.MM,&temp.SS);
			map<int,int>::iterator iter=park_info.high_bound(temp);
			if(iter==park_info.begin())
				printf("0\n");
			else
			{
				--iter;
				printf("%d\n",iter->second);
			}
		}
		sort(longest_array.begin(),longest_array.end());
		for(int y=0;y<longest_array.size();++y)
		   printf("%s ",longest_array[i].c_str());
		printf("%d:%d:%d\n",longest_length/3600,(longest_length%3600)/60,longest_length%60);
	}
	return 0;
}
