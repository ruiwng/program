#include  <stdio.h>
#include  <string.h>
#include  <vector>
#include  <algorithm>
#include  <queue>
using namespace std;

struct person
{
    char name[10];
    int age;
    int net_worth;
    bool operator<(const person& p) const
    {
        if(this->net_worth!=p.net_worth)
            return this->net_worth>p.net_worth;
        if(this->age!=p.age)
            return this->age<p.age;
        return strcmp(this->name,p.name)<0;
    }
};

struct info
{
    person p;
    int index;
    info(const person& p1,int i):p(p1),index(i){
        
    }
    bool operator<(const info& i) const
    {
        return !(this->p<i.p);
    }
};

int main()
{
    int total,query;
    vector<vector<person> > person_array(201);
    while(scanf("%d%d",&total,&query)!=EOF)
    {
        for(int i=0;i<total;++i)
        {
            person p;
            scanf("%s%d%d",p.name,&p.age,&p.net_worth);
            person_array[p.age].push_back(p);
        }
        for(int i=1;i<=200;++i)
            sort(person_array[i].begin(),person_array[i].end());
        for(int i=0;i<query;++i)
        {
            int output,amin,amax;
            scanf("%d%d%d",&output,&amin,&amax);
            printf("Case #%d:\n",i+1);
            priority_queue<info> person_queue;
            for(int j=amin;j<=amax;++j)
            {
                if(!person_array[j].empty())
                    person_queue.push(info(person_array[j][0],0));
            }
            if(person_queue.empty())
                printf("None\n");
            else
            {
                while(!person_queue.empty()&&output>0)
                {
                    info info_ref=person_queue.top();
                    person_queue.pop();
                    printf("%s %d %d\n",info_ref.p.name,info_ref.p.age,info_ref.p.net_worth);
                    if(person_array[info_ref.p.age].size()>info_ref.index+1)
                        person_queue.push(info(person_array[info_ref.p.age][info_ref.index+1],info_ref.index+1));
                    --output;
                }
            }
        }
    }
    return 0;
}
