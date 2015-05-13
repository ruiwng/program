#include  <stdio.h>
#include  <string.h>

char pre_order[30];
char post_order[30];
int m;

long long factorial[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,
	1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};
                                                                                         
long long recurse(int pre_start,int post_start,int len)
{
	long long c=1;
	int num=0;
	int i=pre_start+1;
	int j=post_start;
	while(i<pre_start+len)
	{
		int temp=j;
		while(pre_order[i]!=post_order[j])
			++j;
		++j;
		c*=recurse(i,temp,j-temp);
		++num;
		i+=j-temp;
	}
	return factorial[m]/factorial[num]/factorial[m-num]*c;
}

int main()
{
	while(scanf("%d",&m)!=EOF&&m)
	{
		scanf("%s%s",pre_order,post_order);
		printf("%lld\n",recurse(0,0,strlen(pre_order)));
	}
	return 0;
}