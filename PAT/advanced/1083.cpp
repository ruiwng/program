#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;

struct record
{
	char name[12];
	char id[12];
	int grade;
};

bool cmp(const record* lhs,const record* rhs)
{
	return lhs->grade>rhs->grade;
}

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		vector<record> record_array(num);
		for(unsigned int i=0;i<num;++i)
			scanf("%s %s %d",record_array[i].name,record_array[i].id,
			&record_array[i].grade);
		vector<record*> record_info;
		int low_grade,high_grade;
		scanf("%d %d",&low_grade,&high_grade);
		for(unsigned int i=0;i<num;++i)
		{
			if(record_array[i].grade>=low_grade&&record_array[i].grade<=high_grade)
				record_info.push_back(&record_array[i]);
		}
		if(record_info.empty())
			printf("NONE\n");
		else
		{
			sort(record_info.begin(),record_info.end(),cmp);
			size_t length=record_info.size();
			for(size_t i=0;i<length;++i)
			   printf("%s %s\n",record_info[i]->name,record_info[i]->id);
		}
	}
	return 0;
}