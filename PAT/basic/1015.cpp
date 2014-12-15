#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
     int num;
     int score1;
     int score2;
}student;

bool compare(student stu1,student stu2)
{
     if((stu1.score1+stu1.score2)!=(stu2.score1+stu2.score2))
           return (stu1.score1+stu1.score2)>(stu2.score1+stu2.score2);
     if(stu1.score1!=stu2.score1)
           return stu1.score1>stu2.score1;
     return stu1.num<stu2.num;
}

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
     for(int i=0;i<4;i++)
     {
       sort(numVec[i].begin(),numVec[i].end(),compare);
     }
     printf("%d\n",cnt);
     for(int i=0;i<4;i++)
     {
          for(vector<student>::const_iterator it=numVec[i].begin();it<numVec[i].end();++it)
          {
                printf("%d %d %d\n",it->num,it->score1,it->score2);
           }
     }
     return 0;
}