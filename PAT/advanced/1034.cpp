#include  <stdio.h>
#include  <map>
#include  <string>
#include  <vector>
#include  <algorithm>

using namespace std;

struct node_info
{
	vector<string> adjacency_info;
	bool known;
	unsigned int time_sum;
	node_info():adjacency_info(),known(false),time_sum(0){}
};

struct gang_info
{
	string head;
	unsigned int gang_number;
	bool operator<(const gang_info& info) const
	{
		return this->head<info.head;
	}
	gang_info(string h,unsigned int g):head(h),gang_number(g){}
};

void DFS(map<string,node_info>& array,const string& str,string& head_of_gang,unsigned int& gang_number,unsigned int& time_s,
		 unsigned int& current_max)
{
	node_info& info_temp=array[str];
	info_temp.known=true;
	gang_number++;
	time_s+=info_temp.time_sum;
	vector<string>& adjacency_temp=info_temp.adjacency_info;
	if(info_temp.time_sum>current_max)
	{
		head_of_gang=str;
		current_max=info_temp.time_sum;
	}
	for(unsigned int i=0;i<adjacency_temp.size();++i)
	{
		if(array[adjacency_temp[i]].known)
			continue;
		DFS(array,adjacency_temp[i],head_of_gang,gang_number,time_s,current_max);
	}
}

int main()
{
	unsigned int number_call,weight_threshold;
	while(scanf("%u %u",&number_call,&weight_threshold)!=EOF)
	{
		map<string,node_info> info_array;
		for(unsigned int i=0;i<number_call;++i)
		{
			char str_temp1[4],str_temp2[4];
			unsigned int call_time;
			scanf("%s %s %u",str_temp1,str_temp2,&call_time);

			node_info& node_info1=info_array[str_temp1];
			vector<string>::iterator iter_result=find(node_info1.adjacency_info.begin(),node_info1.adjacency_info.end(),
				str_temp2);
			if(iter_result==node_info1.adjacency_info.end())
			    node_info1.adjacency_info.push_back(str_temp2);
			node_info1.time_sum+=call_time;
			
			node_info& node_info2=info_array[str_temp2];
			iter_result=find(node_info2.adjacency_info.begin(),node_info2.adjacency_info.end(),
				str_temp1);
			if(iter_result==node_info2.adjacency_info.end())
			   node_info2.adjacency_info.push_back(str_temp1);
			node_info2.time_sum+=call_time;
		}

		vector<gang_info> gang_array;
		for(map<string,node_info>::iterator iter=info_array.begin();iter!=info_array.end();++iter)
	    {
			if(iter->second.known)
				continue;
			unsigned int time_sum=0;
			string head=iter->first;
			unsigned int gang_number=0;
			unsigned int current_max=iter->second.time_sum;

			DFS(info_array,iter->first,head,gang_number,time_sum,current_max);

			if(gang_number>2&&time_sum/2>weight_threshold)
			  gang_array.push_back(gang_info(head,gang_number));
	    }
		sort(gang_array.begin(),gang_array.end());
		printf("%u\n",gang_array.size());
		for(unsigned int i=0;i<gang_array.size();++i)
		  printf("%s %u\n",gang_array[i].head.c_str(),gang_array[i].gang_number);
	}
	return 0;	
}