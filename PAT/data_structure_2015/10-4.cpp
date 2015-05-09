#include  <stdio.h>
#include  <vector>
#include  <algorithm>
#include  <queue>
#include  <string>
#include  <functional>
using namespace std;

struct people
{
	string name;
	int age;
	int net_worth;
	people(string n,int a,int w):name(n),age(a),net_worth(w){}
	bool operator<(const people &p) const
	{
		if(this->net_worth!=p.net_worth)
			return this->net_worth>p.net_worth;
		return this->name<p.name;
	}
	bool operator>(const people &p) const
	{
		if(this->net_worth!=p.net_worth)
			return this->net_worth<p.net_worth;
		if(this->age!=p.age)
			return this->age>p.age;
		return this->name>p.name;
	}
};

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		vector<vector<people> > people_array(201);
		for(int i=0;i<n;++i)
		{
			char str[10];
			int age,worth;
			scanf("%s%d%d",str,&age,&worth);
			people_array[age].push_back(people(str,age,worth));
		}
		for(int i=1;i<=200;++i)
			sort(people_array[i].begin(),people_array[i].end());
		for(int i=0;i<k;++i)
		{
			int num,start,end;
			scanf("%d%d%d",&num,&start,&end);
			printf("Case #%d:\n",i+1);
			vector<int> current_pos(201,0);
			priority_queue<people,deque<people>,greater<people> > people_queue;
			for(int j=start;j<=end;++j)
			{
				if(!people_array[j].empty())
				{
					people_queue.push(people_array[j][0]);
					++current_pos[j];
				}
			}
			if(people_queue.empty())
				printf("None\n");
			else
			{
				while(num!=0&&!people_queue.empty())
				{
					--num;
					const people& temp=people_queue.top();
					printf("%s %d %d\n",temp.name.c_str(),temp.age,temp.net_worth);
				    if(current_pos[temp.age]<people_array[temp.age].size())
						people_queue.push(people_array[temp.age][current_pos[temp.age]++]);
					people_queue.pop();
				}
			}
		}
	}
	return 0;
}