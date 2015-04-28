#include  <stdlib.h>
#include  <string.h>

int countPrimes(int n) {
    char *p=(char*)malloc(n);
	memset(p,0,n*sizeof(char));
	int prime_num=0;
	for(int i=2;i<n;++i)
	{
		if(p[i]==0)
		{
			++prime_num;
			for(int k=i<<1;k<n;k+=i)
				p[k]=1;
		}
	}
	free(p);
	return prime_num;
}

int main()
{
	int num=countPrimes(5);
	num=countPrimes(6);
	return 0;
}