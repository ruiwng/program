#include  <stdio.h>
#include  <string.h>

struct date
{
	int year;
	int month;
	int day;
	date(int y=0,int m=0,int d=0):year(y),month(m),day(d){}
	bool operator<(const date& d) const
	{
		if(year!=d.year)
			return year<d.year;
		if(month!=d.month)
			return month<d.month;
		return day<d.day;
	}
	bool operator==(const date& d)const
	{
		return year==d.year&&month==d.month&&day==d.day;
	}
	bool operator<=(const date& d) const
	{
		return operator<(d)||operator==(d);
	}
};

bool is_leap(int year)
{
	return (year%4==0&&year%100!=0)||year%400==0;
}

int month_day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int record[102][13][32];
date end_day(2001,11,4);

int day_count(const date& d)
{
	if(is_leap(d.year)&&d.month==2)
		return 29;
	else
		return month_day[d.month];

}

date day_add(const date& d)
{
	date result(d);
	if(++result.day>day_count(result))
	{
		result.day=1;
		if(++result.month>12)
		{
			result.month=1;
			++result.year;
		}
	}
	return result;
}

date month_add(const date& d)
{
	date result(d);
	if(++result.month>12)
	{
		result.month=1;
		++result.year;
	}
	return result;
}

int win(const date& d)
{
	if(d==end_day)
		return -1;
	if(end_day<d)
		return 1;
	int &temp=record[d.year-1900][d.month][d.day];
	if(temp!=0)
		return temp;
	int result=win(day_add(d));
    if(result==1)
	{
		date t2=month_add(d);
		if(t2.day<=day_count(t2)&&t2<=end_day)
			result=win(t2);
	}
	return (temp=-result);
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(record,0,sizeof(record));
		for(int i=0;i<n;++i)
		{
			date d;
			scanf("%d%d%d",&d.year,&d.month,&d.day);
			if(win(d)==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
