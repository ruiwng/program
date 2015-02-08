#include  <stdio.h>

inline double abs_double(double n)
{
	return n<0.0?-n:n;
}

int main()
{
	bool first=true;
	int numerator,denominator;
	while(scanf("%d%d",&numerator,&denominator)!=EOF)
	{
		if(first)
			first=false;
		else
			printf("\n");
		double real_value=static_cast<double>(numerator)/denominator;
		double close_value=-1.0;
		for(int i=1;i<=denominator;++i)
		{
			int n1=real_value*i;
			int n2=n1+1;
			double temp1=static_cast<double>(n1)/i;
			double temp2=static_cast<double>(n2)/i;
			int n;
			double close_temp;
			if(abs_double(real_value-temp1)<abs_double(real_value-temp2))
			{
			    n=n1;
				close_temp=temp1;
			}
			else
			{
				n=n2;
				close_temp=temp2;
			}
			if(abs_double(real_value-close_temp)<abs_double(real_value-close_value))
			{
				printf("%d/%d\n",n,i);
				close_value=close_temp;
				if(real_value==close_value)
					break;
			}
		}
	}
	return 0;
}
