#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;

typedef struct
{
	unsigned int number;
	float exam_grade;
	float interview_grade;
	float final_grade;
	vector<unsigned int> choice;
	unsigned int final_school;
}applicant;

bool cmp(const applicant* app1,const applicant* app2)
{
	if(app1->final_grade!=app2->final_grade)
		return app1->final_grade>app2->final_grade;
	return app1->exam_grade>app2->exam_grade;
}

typedef struct
{
	unsigned int students_number;
	vector<unsigned int> final_student;
}school;
int main()
{
	unsigned int number_applicant,number_school,number_choices;
	while(scanf("%u %u %u",&number_applicant,&number_school,&number_choices)!=EOF)
	{
		vector<school> school_array(number_school);
		school school_temp;
		for(unsigned int i=0;i<number_school;++i)
		{
			scanf("%u",&school_temp.students_number);
			school_array[i]=school_temp;
		}
		vector<applicant> applicant_array(number_applicant);
		vector<applicant*> applicant_pointer(number_applicant);
		for(unsigned int i=0;i<number_applicant;++i)
		{
			scanf("%f %f",&applicant_array[i].exam_grade,&applicant_array[i].interview_grade);
			applicant_array[i].final_grade=(applicant_array[i].exam_grade+applicant_array[i].interview_grade)/2;
			applicant_array[i].choice.resize(number_choices);
			applicant_array[i].number=i;
			for(unsigned int j=0;j<number_choices;++j)
			   scanf("%u",&applicant_array[i].choice[j]);
			applicant_pointer[i]=&applicant_array[i];
		}

		sort(applicant_pointer.begin(),applicant_pointer.end(),cmp);

		for(vector<applicant*>::iterator iter=applicant_pointer.begin();iter!=applicant_pointer.end();++iter)
		{
			applicant& applicant_temp=**iter;
			vector<unsigned int>& choice_temp=applicant_temp.choice;
			for(vector<unsigned int>::iterator iter_choice=choice_temp.begin();iter_choice!=choice_temp.end();++iter_choice)
			{
				school& school_temp=school_array[*iter_choice];
				bool lucky_choose=false;
				if(school_temp.students_number>0)
				{
					school_array[*iter_choice].final_student.push_back(applicant_temp.number);
					school_temp.students_number--;
					applicant_temp.final_school=*iter_choice;
					lucky_choose=true;
					break;
				}
				else if(school_temp.students_number==0)
				{
					vector<applicant*>::iterator iter_temp=iter;
					if(iter_temp==applicant_pointer.begin())
						break;
					else
					   iter_temp--;
					while(true)
					{
						if((**iter_temp).final_grade!=applicant_temp.final_grade||
							(**iter_temp).exam_grade!=applicant_temp.exam_grade)
							break;
						if((**iter_temp).final_school==*iter_choice)
						{
							school_temp.final_student.push_back(applicant_temp.number);
							lucky_choose=true;
							break;
						}
						if(iter_temp==applicant_pointer.begin())
							break;
						else
							iter_temp--;
					}
				}
				if(lucky_choose)
					break;
			}
		}

		for(vector<school>::iterator iter=school_array.begin();iter!=school_array.end();++iter)
		{
			vector<unsigned int>& student_temp=iter->final_student;
			sort(student_temp.begin(),student_temp.end());
			if(!student_temp.empty())
			{
				vector<unsigned int>::iterator iter_temp=student_temp.begin();
				printf("%u",*iter_temp);
				for(++iter_temp;iter_temp!=student_temp.end();++iter_temp)
				  printf(" %u",*iter_temp);
			}
			printf("\n");
		}
	}
	return 0;
}