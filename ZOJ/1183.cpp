/*
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

inline int satis_func(int t)
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
    record_array[index]=record(1,number,dissatisfy);
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

*/

#include  <stdio.h>
#include  <string.h>
#include  <vector>
using namespace std;

struct record
{
    int topic_time;
    int number;
    int dissatisfy;
    record(int t=0,int n=0,int d=0):topic_time(t),number(n),dissatisfy(d){
        
    }
};

int L,C;
int n;

inline int satis_func(int t)
{
    if(t==0)
        return 0;
    else if(t>=1&&t<=10)
        return -C;
    else
        return (t-10)*(t-10);
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
                vector<record> record_array(n+1);
                for(int j=0;j<n;++j)
                    scanf("%d",&record_array[j].topic_time);

                for(int j=n-1;j>=0;j--)
                {
                    int lecture_time=L;
                    int k=j;
                    while(k<n)
                    {
                        lecture_time-=record_array[k++].topic_time;
                        if(lecture_time<0)
                            break;
                        if(record_array[j].number==0||(record_array[k].number+1<record_array[j].number)
                           ||(record_array[k].number+1==record_array[j].number&&record_array[j].dissatisfy>record_array[k].dissatisfy+satis_func(lecture_time)))
                            {
                                record_array[j].number=record_array[k].number+1;
                                record_array[j].dissatisfy=record_array[k].dissatisfy+satis_func(lecture_time);
                            }
                    }
                }
                
                if(case_number!=0)
                    printf("\n");
                printf("Case %d:\n\n",++case_number);
                printf("Minimum number of lectures: %d\n",record_array[0].number);
                printf("Total dissatisfaction index: %d\n",record_array[0].dissatisfy);
            }
        }
    }
    return 0;
}
