#include  <stdio.h>
#include  <vector>
#include  <algorithm>

using namespace std;


typedef struct
{
	char name[12];
	char gender;
	char id[12];
	int grade;
}student_info;

bool operator<(const student_info& stu1,const student_info& stu2)
{
	return stu1.grade<stu2.grade;
}

bool operator>(const student_info& stu1,const student_info& stu2)
{
	return stu1.grade>stu2.grade;
}

int main()
{
	unsigned int student_num;
	while(scanf("%u",&student_num)!=EOF)
	{
		vector<student_info> male_array;
		vector<student_info> female_array;
		for(unsigned int i=0;i<student_num;i++)
		{
			student_info student_temp;
			scanf("%s %c %s %d",student_temp.name,&student_temp.gender,
				student_temp.id,&student_temp.grade);
			if(student_temp.gender=='M')
				male_array.push_back(student_temp);
			else
				female_array.push_back(student_temp);
		}

		vector<student_info>::iterator iter_female=max_element(female_array.begin(),female_array.end());
		if(iter_female!=female_array.end())
			printf("%s %s\n",iter_female->name,iter_female->id);
		else
			printf("Absent\n");
		vector<student_info>::iterator iter_male=min_element(male_array.begin(),male_array.end());
		if(iter_male!=male_array.end())
			printf("%s %s\n",iter_male->name,iter_male->id);
		else
			printf("Absent\n");
		if(iter_female!=female_array.end()&&iter_male!=male_array.end())
			printf("%d\n",iter_female->grade-iter_male->grade);
		else
			printf("NA\n");
	}
	return 0;
}