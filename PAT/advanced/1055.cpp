/*
#include  <stdio.h>
#include  <string>
#include  <vector>
#include  <algorithm>
using namespace std;

typedef struct 
{
	string name;
	unsigned int age;
	int worth;
}personal_info;

struct info_cmp
{
	bool operator()(const personal_info* info1,const personal_info* info2) const
	{
		if(info1->worth!=info2->worth)
			return info1->worth>info2->worth;
		if(info1->age!=info2->age)
			return info1->age<info2->age;
		return info1->name<info2->name;
	}
};

typedef struct
{
	unsigned int number;
	unsigned int age_min;
	unsigned int age_max;
}query_info;

int main()
{
	unsigned int total,query_number;
	
	while(scanf("%u %u",&total,&query_number)!=EOF)
	{
		vector<personal_info> total_persons(total);
		vector<personal_info*> total_pointer(total);
		vector<unsigned int> age_array(201);

		char name_temp[10];
		for(unsigned int i=0;i<total;++i)
		{
			scanf("%s %u %d",name_temp,&total_persons[i].age,&total_persons[i].worth);
			total_persons[i].name=name_temp;
			total_pointer[i]=&total_persons[i];
			age_array[total_persons[i].age]++;
		}
		sort(total_pointer.begin(),total_pointer.end(),info_cmp());
		vector<query_info> query_array(query_number);
		for(unsigned int i=0;i<query_number;++i)
			scanf("%u %u %u",&query_array[i].number,&query_array[i].age_min,&query_array[i].age_max);


		for(unsigned int i=0;i<query_number;++i)
		{
			unsigned int query_temp=0;
			for(unsigned int j=query_array[i].age_min;j<=query_array[i].age_max;++j)
			{
				query_temp+=age_array[j];
				if(query_temp>=query_array[i].number)
				{
					query_temp=query_array[i].number;
					break;
				}
			}
			printf("Case #%u:\n",i+1);
			if(query_temp==0)
			{
				printf("None\n");
				continue;
			}
			unsigned int query_current=0;
			for(unsigned int j=0;j<total;j++)
			{
				if(total_pointer[j]->age>=query_array[i].age_min&&total_pointer[j]->age<=query_array[i].age_max)
				{
				    printf("%s %u %d\n",total_pointer[j]->name.c_str(),total_pointer[j]->age,total_pointer[j]->worth);
					if(++query_current==query_temp)
						break;
				}
			}
		}
	}
	return 0;
}*/
#include  <stdio.h>
#include  <string>
#include  <vector>
#include  <algorithm>
using namespace std;

typedef struct 
{
	string name;
	unsigned int age;
	int worth;
}personal_info;

struct info_cmp
{
	bool operator()(const personal_info* info1,const personal_info* info2) const
	{
		if(info1->worth!=info2->worth)
			return info1->worth>info2->worth;
		if(info1->age!=info2->age)
			return info1->age<info2->age;
		return info1->name<info2->name;
	}
};

typedef struct
{
	unsigned int number;
	unsigned int age_min;
	unsigned int age_max;
}query_info;

int main()
{
	unsigned int total,query_number;
	
	while(scanf("%u %u",&total,&query_number)!=EOF)
	{
		vector<personal_info> total_persons(total);
		vector<personal_info*> total_pointer(total);
		vector<vector<personal_info*> > age_hash(201);
		vector<unsigned int> age_array(201);

		char name_temp[10];
		for(unsigned int i=0;i<total;++i)
		{
			scanf("%s %u %d",name_temp,&total_persons[i].age,&total_persons[i].worth);
			total_persons[i].name=name_temp;
			total_pointer[i]=&total_persons[i];
			age_hash[total_persons[i].age].push_back(&total_persons[i]);
			age_array[total_persons[i].age]++;
		}
		vector<query_info> query_array(query_number);
		for(unsigned int i=0;i<query_number;++i)
			scanf("%u %u %u",&query_array[i].number,&query_array[i].age_min,&query_array[i].age_max);

		sort(total_pointer.begin(),total_pointer.end(),info_cmp());
		for(unsigned int i=0;i<query_number;++i)
		{
			if(query_array[i].age_max-query_array[i].age_min<100)
			{
			    vector<personal_info*> info_temp;
			    for(unsigned int j=query_array[i].age_min;j<=query_array[i].age_max;++j)
				   info_temp.insert(info_temp.end(),age_hash[j].begin(),age_hash[j].end());

			    printf("Case #%u:\n",i+1);
			    if(info_temp.empty())
			    {
				   printf("None\n");
				   continue;
			    }

			    unsigned int size_temp;
			    if(info_temp.size()<query_array[i].number)
			    {
				   sort(info_temp.begin(),info_temp.end(),info_cmp());
				   size_temp=info_temp.size();			
			    }
			    else
			    {
				   partial_sort(info_temp.begin(),info_temp.begin()+query_array[i].number,info_temp.end(),info_cmp());
				   size_temp=query_array[i].number;
		    	}

			    unsigned int query_current=0;
			    for(unsigned int j=0;j<size_temp;j++)
				 printf("%s %u %d\n",info_temp[j]->name.c_str(),info_temp[j]->age,info_temp[j]->worth);	
			}
			else
			{
				unsigned int query_temp=0;
			for(unsigned int j=query_array[i].age_min;j<=query_array[i].age_max;++j)
			{
				query_temp+=age_array[j];
				if(query_temp>=query_array[i].number)
				{
					query_temp=query_array[i].number;
					break;
				}
			}
			printf("Case #%u:\n",i+1);
			if(query_temp==0)
			{
				printf("None\n");
				continue;
			}
			unsigned int query_current=0;
			for(unsigned int j=0;j<total;j++)
			{
				if(total_pointer[j]->age>=query_array[i].age_min&&total_pointer[j]->age<=query_array[i].age_max)
				{
				    printf("%s %u %d\n",total_pointer[j]->name.c_str(),total_pointer[j]->age,total_pointer[j]->worth);
					if(++query_current==query_temp)
						break;
				}
			}
			}
		}
	}
	return 0;
}


/*#include  <stdio.h>
#include  <string>
#include  <vector>
#include  <algorithm>
#include  <map>
#include  <functional>

using namespace std;

typedef struct 
{
	string name;
	unsigned int age;
}personal_info;

struct info_cmp
{
	bool operator()(const personal_info& info1,const personal_info& info2) const
	{
		if(info1.age!=info2.age)
			return info1.age<info2.age;
		return info1.name<info2.name;
	}
};

typedef struct
{
	unsigned int number;
	unsigned int age_min;
	unsigned int age_max;
}query_info;

int main()
{
	unsigned int total,query_number;
	
	while(scanf("%u %u",&total,&query_number)!=EOF)
	{
		vector<unsigned int> age_array(201);
		map<int,vector<personal_info>,greater<int> > worth_map;
		char name_temp[10];
		for(unsigned int i=0;i<total;++i)
		{
			unsigned int worth_temp;
			personal_info personal_temp;
			scanf("%s %u %d",name_temp,&personal_temp.age,&worth_temp);
			personal_temp.name=name_temp;
			worth_map[worth_temp].push_back(personal_temp);
			age_array[personal_temp.age]++;
		}

		vector<query_info> query_array(query_number);
		for(unsigned int i=0;i<query_number;++i)
			scanf("%u %u %u",&query_array[i].number,&query_array[i].age_min,&query_array[i].age_max);


		for(unsigned int i=0;i<query_number;++i)
		{
			unsigned int query_temp=0;
			for(unsigned int j=query_array[i].age_min;j<=query_array[i].age_max;++j)
			{
				query_temp+=age_array[j];
				if(query_temp>=query_array[i].number)
				{
					query_temp=query_array[i].number;
					break;
				}
			}
			printf("Case #%u:\n",i+1);
			if(query_temp==0)
			{
				printf("None\n");
				continue;
			}
			unsigned int query_current=0;
			for(map<int,vector<personal_info>,greater<int> >::iterator iter=worth_map.begin();iter!=worth_map.end();++iter)
			{
				vector<personal_info>& personal_temp=iter->second;
				if(personal_temp.empty())
					continue;
				sort(personal_temp.begin(),personal_temp.end(),info_cmp());
				for(vector<personal_info>::const_iterator iter1=personal_temp.begin();iter1!=personal_temp.end();++iter1)
				{
				    if(iter1->age>=query_array[i].age_min&&iter1->age<=query_array[i].age_max)
				    {
				         printf("%s %u %d\n",iter1->name.c_str(),iter1->age,iter->first);
					     if(++query_current==query_temp)
						    break;
				    }
				}
				if(query_current==query_temp)
						    break;
			}
		}
	}
	return 0;
}
*/