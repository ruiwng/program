/*#include  <stdio.h>
#include  <vector>
using namespace std;

int L,C;
bool flag;
int mini_number;
int mini_dissatis;
int n;
vector<int> topic_time;

int satis_func(int t)
{
    if(t==0)
        return 0;
    else if(t>=1&&t<=10)
        return -C;
    else
        return (t-10)*(t-10);
}

void mini_func(int number,int index,int distasfy)
{
    if(index==n)
    {
        if(flag==false||number<mini_number||(number==mini_number&&distasfy<mini_dissatis))
        {
            mini_number=number;
            mini_dissatis=distasfy;
            flag=true;
        }
        return;
    }
    int lecture_time=L;
    while(index<n&&topic_time[index]<lecture_time)
        lecture_time-=topic_time[index++];
    if(index!=n&&topic_time[index]==lecture_time&&topic_time[index]>=1&&topic_time[index]<=10)
    {
        mini_func(number+1,index,distasfy-C);
        mini_func(number+1,index+1,distasfy);
    }
    else
    {
        if(index!=n&&topic_time[index]==lecture_time)
            lecture_time-=topic_time[index++];
        mini_func(number+1,index,distasfy+satis_func(lecture_time));
    }
}
int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        for(int i=0;i<N;++i)
        {
            if(i!=0)
                printf("\n");
            int case_number=0;
            while(scanf("%d",&n)!=EOF&&n)
            {
                scanf("%d%d",&L,&C);
                topic_time.clear();
                topic_time.reserve(n);
                for(int j=0;j<n;++j)
                {
                    int t;
                    scanf("%d",&t);
                    topic_time.push_back(t);
                }
                flag=false;
                mini_func(0,0,0);
                printf("Case %d:\n\n",++case_number);
                printf("Minimum number of lectures: %d\n",mini_number);
                printf("Total dissatisfaction index: %d\n\n",mini_dissatis);
            }
        }
    }
    return 0;
}
*/

#include  <stdio.h>
#include  <string.h>
#include  <vector>
using namespace std;

struct record
{
    int tag;
    int number;
    int dissatisfy;
    record(int t=0,int n=0,int d=0):tag(t),number(n),dissatisfy(d){
        
    }
};

record record_array[1000];
int L,C;
int n;
vector<int> topic_time;

int satis_func(int t)
{
    if(t==0)
        return 0;
    else if(t>=1&&t<=10)
        return -C;
    else
        return (t-10)*(t-10);
}
pair<int,int> mini_func(int index)
{
    if(index==n)
        return make_pair(0,0);
    if(record_array[index].tag==1)
        return make_pair(record_array[index].number,record_array[index].dissatisfy);
    int lecture_time=L;
    int start=index;
    while(index<n&&topic_time[index]<=lecture_time)
        lecture_time-=topic_time[index++];
    int number,dissatisfy;
    bool flag=false;
    do{
        pair<int,int> temp=mini_func(index);
        temp.first+=1;
        temp.second+=satis_func(lecture_time);
        if(!flag||(temp.first<number)||(temp.first==number&&temp.second<dissatisfy))
        {
            flag=true;
            number=temp.first;
            dissatisfy=temp.second;
        }
        --index;
        lecture_time+=topic_time[index];
    }while(index>start);
    record_array[index].tag=1;
    record_array[index].number=number;
    record_array[index].dissatisfy=dissatisfy;
    return make_pair(number,dissatisfy);
}

int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        for(int i=0;i<N;++i)
        {
            if(i!=0)
                printf("\n");
            int case_number=0;
            while(scanf("%d",&n)!=EOF&&n)
            {
                scanf("%d%d",&L,&C);
                topic_time.clear();
                topic_time.reserve(n);
                memset(record_array,0,sizeof(record_array));
                for(int j=0;j<n;++j)
                {
                    int t;
                    scanf("%d",&t);
                    topic_time.push_back(t);
                }
                pair<int,int> result=mini_func(0);
                if(case_number!=0)
                    printf("\n");
                printf("Case %d:\n\n",++case_number);
                printf("Minimum number of lectures: %d\n",result.first);
                printf("Total dissatisfaction index: %d\n",result.second);
            }
        }
    }
    return 0;
}
