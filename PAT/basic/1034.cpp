#include  <stdio.h>

long long gcd(long long m,long long n)
{
	if(m<0)
		m=-m;
	if(n<0)
		n=-n;
	long long temp;
	while(n!=0)
	{
		temp=m%n;
		m=n;
		n=temp;
	}
	return m;
}

struct rational
{
	long long numerator;
	long long denominator;
	rational(long long n=0,long long d=1):numerator(n),denominator(d)
	{
		
	}
	void init()
	{
		long long temp=gcd(numerator,denominator);
		numerator/=temp;
		denominator/=temp;
	}
};

rational operator+(const rational& lhs,const rational& rhs)
{
	long long temp=gcd(lhs.denominator,rhs.denominator);
	long long lcm=lhs.denominator/temp*rhs.denominator;
	rational t;
	t.denominator=lcm;
	t.numerator=rhs.denominator/temp*lhs.numerator+lhs.denominator/temp*rhs.numerator;
	t.init();
	return t;
}

rational operator-(const rational& lhs,const rational& rhs)
{
	long long temp=gcd(lhs.denominator,rhs.denominator);
	long long lcm=lhs.denominator/temp*rhs.denominator;
	rational t;
	t.denominator=lcm;
	t.numerator=rhs.denominator/temp*lhs.numerator-lhs.denominator/temp*rhs.numerator;
	t.init();
	return t;
}

rational operator*(const rational& lhs,const rational& rhs)
{
	rational t(lhs.numerator*rhs.numerator,lhs.denominator*rhs.denominator);
	t.init();
	return t;
}

rational operator/(const rational& lhs,const rational& rhs)
{
	rational t(lhs.numerator*rhs.denominator,lhs.denominator*rhs.numerator);
	if(t.denominator<0)
	{
		t.denominator=-t.denominator;
		t.numerator=-t.numerator;
	}
	t.init();
	return t;
}

void print(rational r)
{
	if(r.numerator==0)
	{
		printf("0");
		return;
	}
	int negative=0;
	if(r.numerator<0)
	{
		negative=1;
		r.numerator=-r.numerator;
	}
	long long t=r.numerator/r.denominator;
	long long m=r.numerator%r.denominator;
	if(negative)
		printf("(-");
	if(t!=0)
	   printf("%lld",t);
	if(m!=0)
	{
		if(t!=0)
			printf(" ");
		printf("%lld/%lld",m,r.denominator);
	}
	if(negative)
		printf(")");
}

int main()
{
	rational num1,num2;
	while(scanf("%lld/%lld %lld/%lld",&num1.numerator,&num1.denominator,
		&num2.numerator,&num2.denominator)!=EOF)
	{
		num1.init();
		num2.init();

		rational t;

		print(num1);
		printf(" + ");
		print(num2);
		printf(" = ");
		t=num1+num2;
		print(t);
		printf("\n");

		print(num1);
		printf(" - ");
		print(num2);
		printf(" = ");
		t=num1-num2;
		print(t);
		printf("\n");

		print(num1);
		printf(" * ");
		print(num2);
		printf(" = ");
		t=num1*num2;
		print(t);
		printf("\n");
	
		print(num1);
		printf(" / ");
		print(num2);
		printf(" = ");
		if(num2.numerator==0)
			printf("Inf");
		else
		{
			t=num1/num2;
			print(t);
		}
		printf("\n");
	}
	return 0;
}
