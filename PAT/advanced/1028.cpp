#include  <stdio.h>
#include  <string.h>
#include  <vector>
#include  <algorithm>
#include  <string>
using namespace std;

typedef struct
{
	int number;
	//char name[10];
	string name;
	int grade;
}STU;

bool comp1(STU stu1,STU stu2)
{
	return stu1.number<stu2.number;
}

bool comp2(STU stu1,STU stu2)
{
	if(stu1.name!=stu2.name)
		return stu1.name<stu2.name;
	return stu1.number<stu2.number;
}

bool comp3(STU stu1,STU stu2)
{
	if(stu1.grade!=stu2.grade)
       return stu1.grade<stu2.grade;
	return stu1.number<stu2.number;
}

typedef bool (*pComp)(STU stu1,STU stu2);

pComp p[3]={&comp1,&comp2,&comp3};
int main()
{
	int stuNum,Column;
	vector<STU> stuVec;
	while(scanf("%d %d",&stuNum,&Column)!=EOF)
	{
		while(!stuVec.empty())
		   stuVec.pop_back();
		for(int i=0;i<stuNum;i++)
		{
			STU stuTemp;
			char name_temp[10];
			scanf("%d %s %d",&stuTemp.number,name_temp,&stuTemp.grade);
			stuTemp.name=name_temp;
			stuVec.push_back(stuTemp);
		}
		sort(stuVec.begin(),stuVec.end(),p[Column-1]);
		for(vector<STU>::iterator iter=stuVec.begin();iter!=stuVec.end();iter++)
		  printf("%06d %s %d\n",iter->number,iter->name.c_str(),iter->grade);
	}
	return 0;
}