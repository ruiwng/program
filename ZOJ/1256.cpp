#include  <stdio.h>

const char* month_name[13]=
    {
        "","January","February","March","April","May","June","July","August","September",
        "October","November","December",
    };

const char* week_name[7]=
    {
        "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"
    };

int day_time[13]={
    0,31,28,31,30,31,30,31,31,30,31,30,31
};

struct date
{
    int day;
    int month;
    int year;
    date(int d=1,int m=1,int y=1):day(d),month(m),year(y){
        
    }
    bool operator<(const date& d) const
    {
        if(this->year!=d.year)
            return this->year<d.year;
        if(this->month!=d.month)
            return this->month<d.month;
        return this->day<d.day;
    }
    bool operator==(const date& d) const
    {
        return this->year==d.year&&this->month==d.month&&this->day==d.day;
    }
    bool operator>(const date& d) const
    {
        return !(operator<(d)||operator==(d));
    }
};


date d;

bool is_leap(int year)
{
    if(d<date(3,9,1752))
       return year%4==0;
    else
        return (year%4==0&&year%100!=0)||(year%400==0);
}


bool is_rational(const date& t)
{
    if(t.month>12)
        return false;
    if(is_leap(t.year)&&d.month==2)
        return t.day<=29;
    return t.day<=day_time[d.month];
}

int main()
{
    freopen("test.txt","r",stdin);
    while(scanf("%d%d%d",&d.month,&d.day,&d.year)!=EOF)
    {
        if(d.month==0&&d.day==0&&d.year==0)
            break;

        if(!is_rational(d)||(d>date(2,9,1752)&&d<date(14,9,1752)))
            printf("%d/%d/%d is an invalid date.\n",d.month,d.day,d.year);
        else
        {
            date temp(1,1,1);
            int day_count=0;
            while(temp.year<d.year)
            {
                if(is_leap(temp.year))
                    day_count+=366;
                else
                    day_count+=365;
                ++temp.year;
            }
            while(temp.month<d.month)
            {
                if(is_leap(temp.year)&&temp.month==2)
                    day_count+=29;
                else
                    day_count+=day_time[temp.month];
                ++temp.month;
            }
            day_count+=d.day-temp.day;
            if(d>date(3,9,1752))
               printf("%s %d, %d is a %s\n",month_name[d.month],d.day,d.year,week_name[day_count%7]);
            else
                printf("%s %d, %d is a %s\n",month_name[d.month],d.day,d.year,week_name[(day_count+5)%7]);
        }
    }
    return 0;
}
