#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
     int num;
     int sum;
     int score1;
     int score2;
     bool operator<(const student &s) const
    {
	if(this->sum!=s.sum)
		return this->sum>s.sum;
	if(this->score1!=s.score1)
		return this->score1>s.score1;
	return this->num<s.num;
    }
};

int main()
{
    int n,low,high;
    vector<student> numVec[4];
    scanf("%d %d %d",&n,&low,&high);
    int cnt=n;
    for(int i=0;i<n;++i)
    {
          student stu;
          scanf("%d %d %d",&stu.num,&stu.score1,&stu.score2); 
          stu.sum=stu.score1+stu.score2;
          if(stu.score1<low||stu.score2<low)
          {
             cnt--;
             continue;
           }
          if(stu.score1>=high&&stu.score2>=high)
              numVec[0].push_back(stu);
          else if(stu.score1>=high&&stu.score2<high)
              numVec[1].push_back(stu);
          else if(stu.score1<high&&stu.score2<high&&stu.score1>=stu.score2)
              numVec[2].push_back(stu);
          else
              numVec[3].push_back(stu);    
     }
     for(int i=0;i<4;++i)
     {
       sort(numVec[i].begin(),numVec[i].end());
     }
     printf("%d\n",cnt);
     for(int i=0;i<4;++i)
     {
          for(int j=0;j<numVec[i].size();++j)
                printf("%d %d %d\n",numVec[i][j].num,numVec[i][j].score1,numVec[i][j].score2);
     }
     return 0;
}
