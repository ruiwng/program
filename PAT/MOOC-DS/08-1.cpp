#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;

struct person
{
    int id;
    int virtue;
    int talent;
    int total_grade;
    bool operator<(const person& p) const
    {
        if(this->total_grade!=p.total_grade)
            return this->total_grade>p.total_grade;
        if(this->virtue!=p.virtue)
            return this->virtue>p.virtue;
        return this->id<p.id;
    }
};

struct comp_func
{
    bool operator()(person* lhs,person* rhs) const
    {
        return *lhs<*rhs;
    }
};

int main()
{
    int total,lower,higher;
    while(scanf("%d%d%d",&total,&lower,&higher)!=EOF)
    {
        int ranked=0;
        vector<person> all_person;
        all_person.reserve(total);
        vector<person*> sages;
        vector<person*> noblemen;
        vector<person*> fool_men;
        vector<person*> others;
        for(int i=0;i<total;++i)
        {
            person p;
            scanf("%d%d%d",&p.id,&p.virtue,&p.talent);
            p.total_grade=p.virtue+p.talent;
            if(p.virtue>=lower&&p.talent>=lower)
            {
                all_person.push_back(p);
                ++ranked;
                if(p.virtue>=higher&&p.talent>=higher)
                    sages.push_back(&all_person[ranked-1]);
                else if(p.virtue>=higher&&p.talent<higher)
                    noblemen.push_back(&all_person[ranked-1]);
                else if(p.virtue>=p.talent)
                    fool_men.push_back(&all_person[ranked-1]);
                else
                    others.push_back(&all_person[ranked-1]);
            }
        }
        sort(sages.begin(),sages.end(),comp_func());
        sort(noblemen.begin(),noblemen.end(),comp_func());
        sort(fool_men.begin(),fool_men.end(),comp_func());
        sort(others.begin(),others.end(),comp_func());
        printf("%d\n",ranked);
        int length=sages.size();
        for(int i=0;i<length;++i)
            printf("%08d %d %d\n",sages[i]->id,sages[i]->virtue,sages[i]->talent);
        length=noblemen.size();
        for(int i=0;i<length;++i)
            printf("%08d %d %d\n",noblemen[i]->id,noblemen[i]->virtue,noblemen[i]->talent);
        length=fool_men.size();
        for(int i=0;i<length;++i)
            printf("%08d %d %d\n",fool_men[i]->id,fool_men[i]->virtue,fool_men[i]->talent);
        length=others.size();
        for(int i=0;i<length;++i)
            printf("%08d %d %d\n",others[i]->id,others[i]->virtue,others[i]->talent);
    }
    return 0;
}
