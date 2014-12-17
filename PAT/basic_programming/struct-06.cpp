#include  <stdio.h>

struct complex
{
	double real;
	double imaginary;
	complex(double r=0.0,double i=0.0):real(r),imaginary(i){}
};

bool is_zero(double temp)
{
	return temp>-0.05&&temp<0.05;
}

void print_complex(const complex& comp)
{
	bool temp1=is_zero(comp.real);
	bool temp2=is_zero(comp.imaginary);
	if(!temp1&&!temp2)
	{
		if(comp.imaginary>0.0)
		   printf("%.1lf+%.1lfi",comp.real,comp.imaginary);
		else
			printf("%.1lf%.1lfi",comp.real,comp.imaginary);
	}
	else if(temp1&&!temp2)
		printf("%.1lfi",comp.imaginary);
	else if(!temp1&&temp2)
		printf("%.1lf",comp.real);
	else
		printf("0.0");
}

void print_complex1(const complex& comp)
{
	if(comp.imaginary>=0.0)
	    printf("%.1lf+%.1lfi",comp.real,comp.imaginary);
	else
		printf("%.1lf%.1lfi",comp.real,comp.imaginary);
}
void print(const complex& comp1,const complex& comp2,char oper)
{
	printf("(");
	print_complex1(comp1);
	printf(")");
	printf(" %c ",oper);
	printf("(");
	print_complex1(comp2);
	printf(")");
	printf(" = ");
}
int main()
{
	complex comp1,comp2;
	while(scanf("%lf %lf %lf %lf",&comp1.real,&comp1.imaginary,
		&comp2.real,&comp2.imaginary)!=EOF)
	{
		complex plus_result(comp1.real+comp2.real,comp1.imaginary+comp2.imaginary);
		complex minus_result(comp1.real-comp2.real,comp1.imaginary-comp2.imaginary);
		complex multiple_result(comp1.real*comp2.real-comp1.imaginary*comp2.imaginary,
			comp1.real*comp2.imaginary+comp1.imaginary*comp2.real);
		double temp=comp2.real*comp2.real+comp2.imaginary*comp2.imaginary;
		complex divide_result((comp1.real*comp2.real+comp1.imaginary*comp2.imaginary)/temp,
             (comp1.imaginary*comp2.real-comp1.real*comp2.imaginary)/temp);
		print(comp1,comp2,'+');
		print_complex(plus_result);
		printf("\n");
		print(comp1,comp2,'-');
		print_complex(minus_result);
		printf("\n");
		print(comp1,comp2,'*');
		print_complex(multiple_result);
		printf("\n");
		print(comp1,comp2,'/');
		print_complex(divide_result);
		printf("\n");
	}
	return 0;
}