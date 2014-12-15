/*
#include  <stdio.h>
#include  <string>
#include  <vector>
#include  <map>
#include  <algorithm>

using namespace std;

int main()
{
	unsigned int query_sum,course_sum;
	while(scanf("%u %u",&query_sum,&course_sum)!=EOF)
	{
		map<string,vector<unsigned int> > course_info;
		for(unsigned int i=1;i<=course_sum;++i)
		{
			unsigned int index_temp,sum_temp;
			scanf("%u %u",&index_temp,&sum_temp);
			for(unsigned int j=0;j<sum_temp;++j)
			{
				char str[5];
				scanf("%s",str);
				course_info[str].push_back(index_temp);
			}
		}
		vector<string> query_array(query_sum);
		for(unsigned int i=0;i<query_sum;++i)
		{
			char str_temp[5];
			scanf("%s",str_temp);
			query_array[i]=str_temp;
		}

		for(unsigned int i=0;i<query_sum;++i)
		{
			printf("%s",query_array[i].c_str());
			printf(" %u",course_info[query_array[i]].size());
			if(course_info.empty())
				continue;
			vector<unsigned int>& temp_course=course_info[query_array[i]];
			sort(temp_course.begin(),temp_course.end());
			for(unsigned int j=0;j<temp_course.size();++j)
				printf(" %u",temp_course[j]);
			printf("\n");
		}
	}
	return 0;
}

*/

#include  <iostream>
#include  <vector>
#include  <string>
#include  <algorithm>
using namespace std;

inline unsigned int generate_number(const char* s)
{
	return (s[0]-'A')*6760+(s[1]-'A')*260+(s[2]-'A')*10+s[3]-'0';
}

vector<vector<int> > student_info(180000);
int main()
{
	unsigned int number_student,number_course;
	while(scanf("%u %u",&number_student,&number_course)!=EOF)
	{
		for(unsigned int i=0;i<number_course;i++)
		{
			unsigned int course_index,current_number;
			scanf("%u %u",&course_index,&current_number);
			for(unsigned int j=0;j<current_number;j++)
			{
				char str_temp[5];
				scanf("%s",str_temp);
				student_info[generate_number(str_temp)].push_back(course_index);
			}
		}

		vector<string> student_refer(number_student);
		for(unsigned int i=0;i<number_student;i++)
		{
			char student_temp[5];
			scanf("%s",student_temp);
			student_refer[i]=student_temp;
		}

		for(unsigned int i=0;i<number_student;i++)
		{
			printf("%s ",student_refer[i].c_str());
			unsigned int number_temp=generate_number(student_refer[i].c_str());
			cout<<student_info[number_temp].size();
			if(!student_info[number_temp].empty())
			{
				sort(student_info[number_temp].begin(),student_info[number_temp].end());
				for(unsigned int i=0;i<student_info[number_temp].size();i++)
					printf(" %u",student_info[number_temp][i]);
				printf("\n");
			}
			else
				printf("\n");
		}
	}
	return 0;
}