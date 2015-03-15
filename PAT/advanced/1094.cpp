#include  <stdio.h>
#include  <queue>
#include  <vector>
#include  <map>
using namespace std;

struct member
{
	int generation;
	vector<int> children;
	member():generation(0),children(vector<int>()){}
};

int main()
{
	  int n,m;
	  while(scanf("%d%d",&n,&m)!=EOF)
	  {
		  vector<member> member_array(n+1);
		  for(int i=0;i<m;++i)
		  {
			  int ID,num;
			  scanf("%d%d",&ID,&num);
			  for(int j=0;j<num;++j)
			  {
				  int temp;
				  scanf("%d",&temp);
				  member_array[ID].children.push_back(temp);
			  }
		  }
		  queue<int> family_queue;
		  family_queue.push(1);
		  member_array[1].generation=1;
		  map<int,int> generation_count;
		  while(!family_queue.empty())
		  {
			   int t=family_queue.front();
			   family_queue.pop();
			   ++generation_count[member_array[t].generation];
			   for(int k=0;k<member_array[t].children.size();++k)
			   {
				   family_queue.push(member_array[t].children[k]);
				   member_array[member_array[t].children[k]].generation=member_array[t].generation+1;
			   }
		  }
		  int max_generation=0,max_count=0;
		  for(map<int,int>::iterator iter=generation_count.begin();iter!=generation_count.end();++iter)
		  {
			  if(iter->second>max_count)
			  {
				  max_generation=iter->first;
				  max_count=iter->second;
			  }
		  }
		  printf("%d %d\n",max_count,max_generation);
	  }
	  return 0;
}
