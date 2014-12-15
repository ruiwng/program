/*红黑树算法：最后一个测试点超时，查找相对于哈希表还是慢
#include  <stdio.h>
#include  <string>
#include  <iostream>
#include  <vector>
#include  <map>
#include  <algorithm>
using namespace std;

int main()
{
	unsigned int number_student,number_course;
	while(scanf("%u %u",&number_student,&number_course)!=EOF)
	{
		map<string,vector<int> > student_info;
		for(unsigned int i=0;i<number_course;i++)
		{
			unsigned int course_index,current_number;
			scanf("%u %u",&course_index,&current_number);
			for(unsigned int j=0;j<current_number;j++)
			{
				char str_tmp[5];
				scanf("%s",str_tmp);
				map<string,vector<int> >::iterator iter=student_info.find(str_tmp);
				if(iter==student_info.end())
				{
				 pair<map<string,vector<int> >::iterator,bool> tmp=student_info.insert(make_pair(str_tmp,vector<int>()));
				 if(tmp.second)
					 iter=tmp.first;
				}
				iter->second.push_back(course_index);
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
			map<string,vector<int> >::iterator iter=student_info.find(student_refer[i]);
			if(iter==student_info.end())
				printf("0\n");
			else
			{
				printf("%u",iter->second.size());
				sort(iter->second.begin(),iter->second.end());
				for(unsigned int i=0;i<iter->second.size();i++)
					printf(" %u",iter->second[i]);
				printf("\n");
			}
		}
	}
	return 0;
}
*/

/*哈希表算法*/
/*
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

*/
/*unordered_map版本，竟然最后一个测试点也超时*/
#include  <stdio.h>
#include  <unordered_map>
#include  <string>
#include  <algorithm>
using namespace std;

struct hash_generate:public unary_function<string,size_t>
{
	size_t operator()(const string& s) const
	{
		return (s[0]-'A')*6760+(s[1]-'A')*260+(s[2]-'A')*10+s[3]-'0';
	}
};

unordered_map<string,vector<int>,hash_generate> student_info(180000);
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
				unordered_map<string,vector<int>,hash_generate>::iterator iter=student_info.find(str_temp);
				if(iter==student_info.end())
				{
				 pair<unordered_map<string,vector<int>,hash_generate>::iterator,bool> tmp=student_info.insert(make_pair(str_temp,vector<int>()));
				 if(tmp.second)
					 iter=tmp.first;
				}
				iter->second.push_back(course_index);
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
			vector<int>& temp_info=student_info[student_refer[i]];
			printf("%u",temp_info.size());
		    if(!temp_info.empty())
			{
				sort(temp_info.begin(),temp_info.end());
				for(unsigned int i=0;i<temp_info.size();i++)
			      printf(" %u",temp_info[i]);
			    printf("\n");
			}
			else
			    printf("\n");
		}
	}
	return 0;
}