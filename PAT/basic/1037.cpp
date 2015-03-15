#include  <stdio.h>

struct change
{
	int galleon;
	int sickle;
	int knut;
	change():galleon(0),sickle(0),knut(0){}
	change(const change &c):galleon(c.galleon),sickle(c.sickle),knut(c.knut){}
	bool operator<(const change& c) const
	{
	   if(this->galleon!=c.galleon)
		   return this->galleon<c.galleon;
	   if(this->sickle!=c.sickle)
		   return this->sickle<c.sickle;
	   return this->knut<c.knut;
	}
};

change operator-(const change &lhs,const change &rhs)
{
	change temp(lhs);
	while(temp.knut<rhs.knut)
	{
		temp.knut+=29;
		--temp.sickle;
	}
	temp.knut-=rhs.knut;
	if(temp.sickle<rhs.sickle)
	{
		temp.sickle+=17;
		--temp.galleon;
	}
	temp.sickle-=rhs.sickle;
	temp.galleon-=rhs.galleon;
	return temp;
}

inline void print_change(const change &c)
{
	printf("%d.%d.%d\n",c.galleon,c.sickle,c.knut);
}

int main()
{
	change P,A;
	while(scanf("%d.%d.%d %d.%d.%d",&P.galleon,&P.sickle,&P.knut,&A.galleon,&A.sickle,&A.knut)!=EOF)
	{
		if(A<P)
		{
			printf("-");
			print_change(P-A);
		}
		else
			print_change(A-P);
	}
	return 0;
}
