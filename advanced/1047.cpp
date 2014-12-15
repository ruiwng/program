#include  <stdio.h>
#include  <list>
#include  <string>
#include  <vector>
#include  <algorithm>
using namespace std;

struct cmp_func
{
	bool operator()(const string* pstr1,const string* pstr2) const
	{
		return *pstr1<*pstr2;
	}
};
int main()
{
	int students,courses;
	while(scanf("%d %d",&students,&courses)!=EOF)
	{
		vector<vector<string*> > liVec(courses+1);
		vector<string> name_array(students);
		for(int i=0;i<students;i++)
		{
		   char ch[5];
		   scanf("%s",ch);
		   name_array[i]=ch;
		   int count;
		   scanf("%d",&count);
		   for(int j=0;j<count;j++)
		   {
			   int temp;
			   scanf("%d",&temp);
			   liVec[temp].push_back(&name_array[i]);
		   }
		}
		for(int i=1;i<=courses;i++)
		{
			printf("%d %u\n",i,liVec[i].size());
			sort(liVec[i].begin(),liVec[i].end(),cmp_func());
			for(vector<string*>::const_iterator iter=liVec[i].begin();iter!=liVec[i].end();++iter)
			   printf("%s\n",(*iter)->c_str());
		}
	}
	return 0;
}