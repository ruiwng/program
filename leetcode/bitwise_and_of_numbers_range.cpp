#include  <stdio.h>

int get_num(int n)
{
	if(n==0)
		return 0;
	int k=1;
	while(n!=1)
	{
		n>>=1;
		k<<=1;
	}
	return k;
}

int rangeBitwiseAnd(int m, int n) {
	if(m==n)
		return m;
    int num=0;
	long long x=get_num(m);
	while(m!=0)
	{
	    long long y=x<<1;
		if(n<y)
		{
			if(m>=x)
			{
				num+=x;
				m-=x;
				n-=x;
			}
			else if(n>=x)
				break;
			x>>=1;
		}
		else
			break;
	}
	return num;
}

int main()
{
	printf("%d\n",rangeBitwiseAnd(2147483646, 2147483647));
	return 0;
}