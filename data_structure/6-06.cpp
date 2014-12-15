#include  <stdio.h>
#include  <vector>
#include  <list>
using namespace std;

struct job_info
{
	bool known;
	list<unsigned int> dependency;
	vector<unsigned int> adjacent_node;
    job_info():known(false),dependency(list<unsigned int>()),adjacent_node(vector<unsigned int>()){}
};
int main()
{
	unsigned int number_job;
	while(scanf("%u",&number_job)!=EOF)
	{
		vector<job_info> job_array(number_job+1);
		for(unsigned int i=1;i<=number_job;++i)
		{
			unsigned int number_temp;
			scanf("%u",&number_temp);
			for(unsigned j=0;j<number_temp;++j)
			{
				unsigned int dependency_temp;
				scanf("%u",&dependency_temp);
				job_array[i].dependency.push_back(dependency_temp);
				job_array[dependency_temp].adjacent_node.push_back(i);
			}
		}
	    unsigned int count_num=0;
		while(true)
		{
		   unsigned int i=1;
		   for(;i<=number_job;++i)
		   {
			   if(job_array[i].known)
				   continue;
			   if(job_array[i].dependency.empty())
				   break;
		   }
		   if(i==number_job+1)
			   break;
		   else
		   {
			   ++count_num;
			   job_array[i].known=true;
			   vector<unsigned int>& adjencent_temp=job_array[i].adjacent_node;
			   for(unsigned int j=0;j<adjencent_temp.size();++j)
			   {
				   list<unsigned int>& dependency_temp=job_array[adjencent_temp[j]].dependency;
				   for(list<unsigned int>::iterator iter=dependency_temp.begin();iter!=dependency_temp.end();++iter)
				   {
					   if(*iter==i)
					   {
						   dependency_temp.erase(iter);
						   break;
					   }
				   }
			   }
		   }
		}
		 if(count_num==number_job)
			   printf("1\n");
		 else
			   printf("0\n");
	}
	return 0;
}