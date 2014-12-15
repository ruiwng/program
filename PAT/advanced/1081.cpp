#include  <stdio.h>
#include  <stdlib.h>
using namespace std;
long int gcd(long long a,long long b)
{
	a=abs(a);
	b=abs(b);

	while(a%b!=0)
	{
		long long temp=a%b;
		a=b;
		b=temp;
	}
	return b;
}

struct rational
{
	long long numerator;
	long long denominator;
	rational(long long n=0,long long d=1):numerator(n),denominator(d){}
	rational& operator+=(const rational& r)
	{
		long long gcd_temp=gcd(this->denominator,r.denominator);
		long long denominator_temp=this->denominator*r.denominator/gcd_temp;
		long long numerator_temp=this->numerator*r.denominator/gcd_temp+r.numerator*this->denominator/gcd_temp;
		this->numerator=numerator_temp;
		this->denominator=denominator_temp;
		return *this;
	}
};


int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		rational sum;
		for(unsigned int i=0;i<num;++i)
		{
			rational temp;
			scanf("%lld/%lld",&temp.numerator,&temp.denominator);
			sum+=temp;
			if(sum.numerator!=0)
			{
                 long long gcd_temp=gcd(sum.denominator,sum.numerator);
			     sum.denominator/=gcd_temp;
			     sum.numerator/=gcd_temp;
			}
		}
		if(sum.numerator==0)
			printf("0\n");
		else
		{
			if(sum.denominator==1)
				printf("%lld\n",sum.numerator);
			else if(sum.numerator<sum.denominator)
				printf("%lld/%lld\n",sum.numerator,sum.denominator);
			else if(sum.numerator>sum.denominator)
				printf("%lld %lld/%lld\n",sum.numerator/sum.denominator,sum.numerator%sum.denominator,sum.denominator);
		}
	}
	return 0;
}