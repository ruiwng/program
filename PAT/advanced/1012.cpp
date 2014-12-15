#include  <stdio.h>
#include  <stdlib.h>
#include  <vector>
using namespace std;
typedef struct
{
	int num;
	int C;
	int M;
	int E;
	int A;
}STU;
int main()
{
	int total,check;
	vector<STU> stuVec;
	vector<int> numVec;
	while(scanf("%d %d",&total,&check)!=EOF)
	{
		while(!stuVec.empty())
			stuVec.pop_back();
		while(!numVec.empty())
			numVec.pop_back();
		for(int i=0;i<total;i++)
		{
			STU stu;
			scanf("%d %d %d %d",&stu.num,&stu.C,&stu.M,&stu.E);
			stu.A=(stu.C+stu.M+stu.E)/3;
			stuVec.push_back(stu);
		}
        for(int i=0;i<check;i++)
		{
			int temp;
			scanf("%d",&temp);
			numVec.push_back(temp);
		}
		for(vector<int>::const_iterator iter=numVec.begin();iter!=numVec.end();iter++)
		{
			vector<STU>::const_iterator it=stuVec.begin();
			while(it!=stuVec.end()&&it->num!=*iter)
			   it++;
			if(it==stuVec.end())
				printf("N/A\n");
			else
			{
		   	  int Anum=1,Cnum=1,Mnum=1,Enum=1;
			  for(vector<STU>::const_iterator it1=stuVec.begin();it1!=stuVec.end();it1++)
			  {
				if(it1->A>it->A)
					Anum++;
				if(it1->C>it->C)
					Cnum++;
				if(it1->M>it->M)
					Mnum++;
				if(it1->E>it->E)
					Enum++;
			  }
			  if(Anum<=Cnum&&Anum<=Mnum&&Anum<=Enum)
			    printf("%d A\n",Anum);
			  else if(Cnum<Anum&&Cnum<=Mnum&&Cnum<=Enum)
				printf("%d C\n",Cnum);
			  else if(Mnum<Anum&&Mnum<Cnum&&Mnum<=Enum)
				printf("%d M\n",Mnum);
			  else
				printf("%d E\n",Enum);
			}
		}
	}
	return 0;
}