#include  <stdio.h>
#include  <stdlib.h>
#include  <vector>
#include  <limits>
using namespace std;

unsigned long long func()
{
	unsigned long long x=1;
	for(int i=0;i<63;i++)
		x*=2;
	return x;
}
typedef struct
{
	unsigned long long number;
	bool negative;
}NUM;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
	   vector<int> intVec;
	   while(!intVec.empty())
		   intVec.pop_back();
	   for(int i=0;i<n;i++)
	   {
		   char ch[3][30];
		   scanf("%s %s %s",ch[0],ch[1],ch[2]);
		   NUM num[3];
		   for(int j=0;j<3;j++)
		   {
			   if(ch[j][0]=='-')
			   {
                  num[j].negative=true;
				  sscanf(&ch[j][1],"%llu",&num[j].number);
			   }
			   else
			   {
				   num[j].negative=false;
				   sscanf(&ch[j][0],"%llu",&num[j].number);
			   }
		   }
		   if(num[0].negative&&num[1].negative&&num[0].number==func()&&
			   num[1].number==func())
		   {
			   intVec.push_back(0);
			   continue;
		   }
		   if(!num[0].negative&&!num[1].negative&&num[0].number==func()&&
			   num[1].number==func())
		   {
			   intVec.push_back(1);
			   continue;
		   }
		   NUM temp;
		   if(num[0].negative&&num[1].negative)
		   {
			   temp.negative=true;
			   temp.number=num[0].number+num[1].number;
		   }
		   else if(!num[0].negative&&!num[1].negative)
		   {
			   temp.negative=false;
			   temp.number=num[0].number+num[1].number;
		   }
		   else if(!num[0].negative&&num[1].negative)
		   {
			   if(num[0].number>=num[1].number)
			   {
				   temp.negative=false;
				   temp.number=num[0].number-num[1].number;
			   }
			   else
			   {
				   temp.negative=true;
				   temp.number=num[1].number-num[0].number;
			   }
		   }
		   else
		   {
			   if(num[0].number>num[1].number)
			   {
				   temp.negative=true;
				   temp.number=num[0].number-num[1].number;
			   }
			   else
			   {
				   temp.negative=false;
				   temp.number=num[1].number-num[0].number;
			   }
		   }
		   if(temp.negative&&!num[2].negative)
			   intVec.push_back(0);
		   else if(!temp.negative&&num[2].negative)
			   intVec.push_back(1);
		   else if(temp.negative&&num[2].negative)
		   {
			   if(temp.number<num[2].number)
				   intVec.push_back(1);
			   else
				   intVec.push_back(0);
		   }
		   else
		   {
			   if(temp.number>num[2].number)
				   intVec.push_back(1);
			   else
				   intVec.push_back(0);
		   }
	   }
	   for(unsigned int i=0;i<intVec.size();i++)
	   {
		   if(intVec[i]==0)
			   printf("Case #%u: false\n",i+1);
		   else
			   printf("Case #%u: true\n",i+1);
	   }
	}
	return 0;
}