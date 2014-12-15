#include  <stdio.h>
#include  <stdlib.h>

typedef struct
{
	int h;
	int m;
	int s;
}time;
bool operator>(time t1,time t2)
{
	if(t1.h!=t2.h)
		return t1.h>t2.h;
	if(t1.m!=t2.m)
		return t1.m>t2.m;
	return t1.s>t2.s;
}

bool operator<(time t1,time t2)
{
	return t2>t1;
}
typedef struct
{
	char name[16];
	time t1;
	time t2;
}STU;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		STU first,last,temp;
		for(int i=0;i<n;i++)
		{
			scanf("%s %02d:%02d:%02d %02d:%02d:%02d",temp.name,&temp.t1.h,&temp.t1.m,&temp.t1.s,&temp.t2.h,&temp.t2.m,&temp.t2.s);
			if(i==0)
			{
				first=temp;
				last=temp;
			}
			else
			{
				if(temp.t1<first.t1)
					first=temp;
				if(temp.t2>last.t2)
					last=temp;
			}
		}
		printf("%s %s\n",first.name,last.name);
	}
	return 0;
}