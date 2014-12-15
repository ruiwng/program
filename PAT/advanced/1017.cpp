#include <stdio.h>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
	int HH;
	int MM;
	int SS;
}times;

typedef struct
{
	times arrive;
	unsigned int process;
}customer;

bool operator<(times t1,times t2)
{
	if(t1.HH!=t2.HH)
		return t1.HH<t2.HH;
	if(t1.MM!=t2.MM)
		return t1.MM<t2.MM;
	return t1.SS<t2.SS;
}

bool operator<(customer c1,customer c2)
{
	return c1.arrive<c2.arrive;
}

bool operator==(times t1,times t2)
{
	return t1.HH==t2.HH&&t1.MM==t2.MM&&t1.SS==t2.SS;
}

times operator-(times t1,times t2)
{
	times t;
	if(t1.SS>=t2.SS)
		t.SS=t1.SS-t2.SS;
	else
	{
		t.SS=t1.SS+60-t2.SS;
		if(t1.MM==0)
		{
			t1.HH--;
			t1.MM=59;
		}
		else 
			t1.MM--;
	}
	if(t1.MM>=t2.MM)
		t.MM=t1.MM-t2.MM;
	else
	{
		t.MM=t1.MM+60-t2.MM;
		t1.HH--;
	}
	t.HH=t1.HH-t2.HH;
	return t;
}

bool operator<=(times t1,times t2)
{
	return t1<t2||t1==t2;
}

times operator+(times t,unsigned int minutes)
{
	if(t.MM+minutes>=60)
		t.HH++;
	t.MM=(t.MM+minutes)%60;
    return t;
}

times operator+(times t1,times t2)
{
	times t;
	t.SS=t1.SS+t2.SS;
	if(t.SS>=60)
	{
		t.SS-=60;
		t1.MM++;
	}
	t.MM=t1.MM+t2.MM;
	if(t.MM>=60)
	{
		t.MM-=60;
		t1.HH++;
	}
	t.HH=t1.HH+t2.HH;
	return t;
}


int main()
{
	unsigned int customers_number,windows;
	list<customer> cusVec;
	while(scanf("%u %u",&customers_number,&windows)!=EOF)
	{
		while(!cusVec.empty())
			cusVec.pop_back();
		for(unsigned int i=0;i<customers_number;i++)
		{
			customer cust;
			scanf("%u:%u:%u %u",&cust.arrive.HH,&cust.arrive.MM,&cust.arrive.SS,
				&cust.process);
			cusVec.push_back(cust);
		}
		cusVec.sort();
		vector<times> timeVec(windows);
		for(vector<times>::iterator iter=timeVec.begin();iter!=timeVec.end();++iter)
		{
			iter->HH=8;
			iter->MM=0;
			iter->SS=0;
		}
		times end_time;
		end_time.HH=17;
		end_time.MM=0;
		end_time.SS=0;
		times wait_time;
		wait_time.HH=0;
		wait_time.MM=0;
		wait_time.SS=0;
		unsigned int customer_sum=0;
		while(!cusVec.empty())
		{
			customer cust_temp;
			cust_temp=cusVec.front();
			cusVec.pop_front();
			if(end_time<cust_temp.arrive)
				break;
			else
				customer_sum++;
			vector<times>::iterator iterTemp=min_element(timeVec.begin(),timeVec.end());
			if(cust_temp.arrive<=*iterTemp)
			{
				wait_time=*iterTemp-cust_temp.arrive+wait_time;
			    *iterTemp=*iterTemp+cust_temp.process;
			}
			else
				*iterTemp=cust_temp.arrive+cust_temp.process;
		}
		printf("%.1lf\n",(wait_time.HH*60+wait_time.MM+static_cast<double>(wait_time.SS)/60)/customer_sum);
	}
	return 0;
}