#include  <stdio.h>
#include  <string.h>

struct birthday
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
    birthday(unsigned int y=0,unsigned int m=0,unsigned int d=0):year(y),month(m),day(d){
    }

    bool operator<(const birthday& b) const
    {
        if(this->year!=b.year)
            return this->year<b.year;
        if(this->month!=b.month)
            return this->month<b.month;
        return this->day<b.day;
    }
};

struct person
{
    char name[20];
    birthday birth;
    person():birth(){
        memset(name,'\0',sizeof(name));
    }
    bool operator<(const person& p) const
    {
        this->birth<p.birth;
    }
};

int main()
{
    unsigned int number;
    while(scanf("%u",&number)!=EOF)
    {
        birthday temp1(2014,9,6);
        birthday temp2(1814,9,6);
        person person_temp;
        unsigned int valid_count=0;
        person old_person;
        person small_person;
        bool first=true;
        for(unsigned int i=0;i<number;++i)
        {
            scanf("%s %u/%u/%u",person_temp.name,&person_temp.birth.year,
                  &person_temp.birth.month,&person_temp.birth.day);
            if(temp1<person_temp.birth||person_temp.birth<temp2)
                continue;
            ++valid_count;
            if(first)
            {
                small_person=person_temp;
                old_person=person_temp;
                first=false;
            }
            else
            {
                if(person_temp.birth<old_person.birth)
                    old_person=person_temp;
                else if(small_person.birth<person_temp.birth)
                    small_person=person_temp;
            }
        }
        if(valid_count!=0)
        printf("%u %s %s\n",valid_count,old_person.name,small_person.name);
        else
            printf("0\n");
    }
    return 0;
}
